package format

import (
	"strings"

	"github.com/kelly-lin/12d-lang-server/parser"
	"github.com/kelly-lin/12d-lang-server/protocol"
	sitter "github.com/smacker/go-tree-sitter"
)

func GetIndentationEdits(node *sitter.Node) []protocol.TextEdit {
	result := []protocol.TextEdit{}
	stack := parser.NewStack()
	stack.Push(node)
	for stack.HasItems() {
		currentNode, _ := stack.Pop()
		nodeType := currentNode.Type()
		if isSupportedIndentationNodeType(nodeType) {
			// HACK: we dont yet support formatting the children of for
			// statement nodes. Skip the iteration for now.
			if nodeType == "declaration" && currentNode.Parent() != nil && currentNode.Parent().Type() == "for_statement" {
				continue
			}
			indentLevel := 0
			currentParent := currentNode.Parent()
			for currentParent != nil {
				if currentParent.Type() == "compound_statement" {
					indentLevel++
				}
				currentParent = currentParent.Parent()
			}
			targetIndentation := indentLevel * 4
			currentIndentation := currentNode.StartPoint().Column
			if targetIndentation != int(currentIndentation) {
				sb := strings.Builder{}
				for i := 0; i < targetIndentation; i++ {
					sb.WriteRune(' ')
				}
				newText := sb.String()
				result = append(
					result,
					protocol.TextEdit{
						Range: protocol.Range{
							Start: protocol.Position{
								Line:      uint(currentNode.StartPoint().Row),
								Character: 0,
							},
							End: protocol.Position{
								Line:      uint(currentNode.StartPoint().Row),
								Character: uint(currentNode.StartPoint().Column),
							},
						},
						NewText: newText,
					},
				)
			}
		}
		for i := 0; i < int(currentNode.ChildCount()); i++ {
			stack.Push(currentNode.Child(i))
		}
	}
	return result
}

func isSupportedIndentationNodeType(nodeType string) bool {
	for _, supportedType := range []string{
		"declaration",
		"for_statement",
		"switch_statement",
		"while_statement",
		"if_statement",
		"function_definition",
	} {
		if nodeType == supportedType {
			return true
		}
	}
	return false
}

func GetTrailingWhitespaceEdits(sourceCode []byte) []protocol.TextEdit {
	result := []protocol.TextEdit{}
	lines := strings.Split(string(sourceCode), "\n")
	for idx, line := range lines {
		numSpaces := 0
		for i := len(line) - 1; i >= 0; i-- {
			if line[i] != ' ' {
				break
			}
			numSpaces++
		}
		if numSpaces > 0 {
			result = append(
				result,
				protocol.TextEdit{
					Range: protocol.Range{
						Start: protocol.Position{
							Line:      uint(idx),
							Character: uint(len(line) - numSpaces),
						},
						End: protocol.Position{
							Line:      uint(idx),
							Character: uint(len(line)),
						},
					},
				},
			)
		}
	}
	return result
}
