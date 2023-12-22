package parser

import (
	"context"
	"errors"
	"fmt"

	sitter "github.com/smacker/go-tree-sitter"
)

var ErrNoDefinition = errors.New("no definition found")

// 0 indexed row and column indices of a position in a document.
type Point struct {
	Row    uint32
	Column uint32
}

// Range has a 0 indexed start and end point specifying the row and column
// index of the range. Similar to ranges in programming languages, the end
// point is exclusive.
type Range struct {
	Start Point
	End   Point
}

// Find the definition of the function with the provided identifier inside
// source and returns the range if it was found. If the definition was not found
// then error ErrNoDefinition will be returned.
func FindFuncDefinition(identifier string, source []byte) (Range, error) {
	n, err := sitter.ParseCtx(context.Background(), source, GetLanguage())
	if err != nil {
		return Range{}, err
	}

	pattern := fmt.Sprintf(`(
    (source_file 
        (function_definition
            type: (primitive_type)
            declarator: (function_declarator (identifier) @name)))
    (#eq? @name %q)
)`, identifier)
	q, err := sitter.NewQuery([]byte(pattern), GetLanguage())
	if err != nil {
		return Range{}, err
	}

	qc := sitter.NewQueryCursor()
	qc.Exec(q, n)
	var result Range
	found := false
	for {
		m, ok := qc.NextMatch()
		if !ok {
			break
		}
		m = qc.FilterPredicates(m, source)
		for _, c := range m.Captures {
			start := c.Node.StartPoint()
			result.Start.Row = start.Row
			result.Start.Column = start.Column

			end := c.Node.EndPoint()
			result.End.Row = end.Row
			result.End.Column = end.Column
			found = true
			break
		}
		if found {
			break
		}
	}
	if !found {
		return Range{}, ErrNoDefinition
	}
	return result, nil
}

type Stack struct {
	items []*sitter.Node
	idx   int
}

func NewStack() Stack {
	return Stack{items: []*sitter.Node{}, idx: -1}
}

func (s *Stack) Push(node *sitter.Node) {
	s.idx++
	if s.idx == len(s.items) {
		s.items = append(s.items, node)
		return
	}
	s.items[s.idx] = node
}

func (s *Stack) Pop() (*sitter.Node, error) {
	if !s.HasItems() {
		return nil, errors.New("stack is empty")
	}
	result := s.items[s.idx]
	s.idx--
	return result, nil
}

func (s *Stack) HasItems() bool {
	return s.idx >= 0
}

func NewQueue() Queue {
	return Queue{items: []*sitter.Node{}, idx: 0}
}

type Queue struct {
	items []*sitter.Node
	idx   int
}

func (q *Queue) Enqueue(item *sitter.Node) {
	q.items = append(q.items, item)
}

func (q *Queue) Dequeue() (*sitter.Node, error) {
	if !q.HasItems() {
		return nil, errors.New("no items to dequeue")
	}
	result := q.items[q.idx]
	q.idx++
	return result, nil
}

func (q *Queue) HasItems() bool {
	return len(q.items)-q.idx > 0
}

// Finds the identifier located at the line and column number and returns the
// name if it exists and an error when it does not.
func FindIdentifier(node *sitter.Node, sourceCode []byte, lineNum, colNum uint) (string, error) {
	queue := NewQueue()
	queue.Enqueue(node)
	numSteps := 0
	for queue.HasItems() {
		currentNode, err := queue.Dequeue()
		if err != nil {
			break
		}
		numSteps++
		isOnSameLine := func(n *sitter.Node) bool {
			return uint(n.StartPoint().Row) == lineNum && lineNum == uint(n.EndPoint().Row)
		}
		isInsideColumn := func(n *sitter.Node) bool {
			return uint(n.StartPoint().Column) <= colNum && colNum <= uint(n.EndPoint().Column)
		}
		if currentNode.Type() == "identifier" && isOnSameLine(currentNode) && isInsideColumn(currentNode) {
			fmt.Printf("found node in %d steps\n", numSteps)
			return currentNode.Content(sourceCode), nil
		}
		for i := 0; i < int(currentNode.ChildCount()); i++ {
			currentChild := currentNode.Child(i)
			// Since the tree nodes will be ordered by line numbers, if the
			// child's line number is greater, we do not need to check the other
			// children.
			if uint(currentChild.StartPoint().Row) > lineNum {
				break
			}
			queue.Enqueue(currentChild)
		}
	}
	return "", ErrNoDefinition
}
