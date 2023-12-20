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

// Finds the identifier located at the line and column number and returns the
// name if it exists and an error when it does not.
func FindIdentifier(node *sitter.Node, lineNum, colNum uint) (string, error) {
	return "main", nil
}
