package format

import (
	"strings"

	"github.com/kelly-lin/12d-lang-server/parser"
	"github.com/kelly-lin/12d-lang-server/protocol"
	sitter "github.com/smacker/go-tree-sitter"
)

// Get formatting edits for block indentations,
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

// Get formatting edits for trailing whitespaces.
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

// Get formatting edits for function definitions.
func GetFuncDefEdits(rootNode *sitter.Node) []protocol.TextEdit {
	result := []protocol.TextEdit{}
	for i := 0; i < int(rootNode.ChildCount()); i++ {
		currentNode := rootNode.Child(i)
		if currentNode.Type() != "function_definition" {
			continue
		}
		returnTypeNode := currentNode.ChildByFieldName("type")
		funcDeclarationNode := currentNode.ChildByFieldName("declarator")
		bodyNode := currentNode.ChildByFieldName("body")

		result = append(result, formatReturnTypeAndDeclarationSpacing(funcDeclarationNode, returnTypeNode)...)
		result = append(result, formatDeclarationAndBodySpacing(bodyNode, funcDeclarationNode, returnTypeNode)...)
		result = append(result, formatParamList(funcDeclarationNode)...)
	}
	return result
}

// Formats the spacing between the function return type and declaration. For
// example the spacing between "void" and "Foo" in "void Foo()".
func formatReturnTypeAndDeclarationSpacing(funcDeclarationNode, returnTypeNode *sitter.Node) []protocol.TextEdit {
	result := []protocol.TextEdit{}
	numSpaces := funcDeclarationNode.StartPoint().Column - returnTypeNode.EndPoint().Column
	if numSpaces != 1 {
		lineNum := uint(returnTypeNode.StartPoint().Row)
		result = append(
			result,
			protocol.TextEdit{
				Range: protocol.Range{
					Start: protocol.Position{
						Line:      lineNum,
						Character: uint(returnTypeNode.EndPoint().Column),
					},
					End: protocol.Position{
						Line:      lineNum,
						Character: uint(funcDeclarationNode.StartPoint().Column),
					},
				},
				NewText: " ",
			},
		)
	}
	return result
}

// Get the formatting edits for the spacing between the ending parenthesis of
// the function parameter list and opening body brace. i.e. the space between
// the ")" and "{" in "void Foo() {}".
func formatDeclarationAndBodySpacing(bodyNode, funcDeclarationNode, returnTypeNode *sitter.Node) []protocol.TextEdit {
	result := []protocol.TextEdit{}
	numSpaces := bodyNode.StartPoint().Column - funcDeclarationNode.EndPoint().Column
	if numSpaces != 1 {
		lineNum := uint(returnTypeNode.StartPoint().Row)
		result = append(
			result,
			protocol.TextEdit{
				Range: protocol.Range{
					Start: protocol.Position{
						Line:      lineNum,
						Character: uint(funcDeclarationNode.EndPoint().Column),
					},
					End: protocol.Position{
						Line:      lineNum,
						Character: uint(bodyNode.StartPoint().Column),
					},
				},
				NewText: " ",
			},
		)
	}
	return result
}

// Get formatting edits for the function parameter list.
func formatParamList(funcDeclarationNode *sitter.Node) []protocol.TextEdit {
	var result []protocol.TextEdit
	paramsNode := funcDeclarationNode.ChildByFieldName("parameters")
	startCol := paramsNode.StartPoint().Column
	paramIdx := 0
	lastDeclaratorPos := 0
	numChildren := int(paramsNode.ChildCount())
	if numChildren == 0 {
		return []protocol.TextEdit{}
	}
	// prevLine := paramsNode.Child(0).StartPoint().Row
	for i := 0; i < numChildren; i++ {
		currentNode := paramsNode.Child(i)
		if currentNode.Type() == "parameter_declaration" {
			typeNode := currentNode.ChildByFieldName("type")
			declaratorNode := currentNode.ChildByFieldName("declarator")
			result = append(result, formatParamSpacing(paramIdx, lastDeclaratorPos, startCol, currentNode, typeNode, declaratorNode)...)
			shouldFormatTypeIdentifierSpacing := declaratorNode.StartPoint().Column-typeNode.EndPoint().Column > 1
			if shouldFormatTypeIdentifierSpacing {
				result = append(
					result,
					protocol.TextEdit{
						Range: protocol.Range{
							Start: protocol.Position{
								Line:      uint(typeNode.EndPoint().Row),
								Character: uint(typeNode.EndPoint().Column),
							},
							End: protocol.Position{
								Line:      uint(declaratorNode.StartPoint().Row),
								Character: uint(declaratorNode.StartPoint().Column),
							},
						},
						NewText: " ",
					},
				)
			}

			lastDeclaratorPos = int(declaratorNode.EndPoint().Column)
			// prevLine = uint32(typeNode.StartPoint().Row)
			paramIdx++
		}
	}
	return result
}

// Get formatting edits for the spacing in between parameters. For example,
// The spacing of "Integer a," and "Integer b" "void Foo(Integer a, Integer b)".
// This function will return the edits so that the number of spaces between the
// comma after "a" and "Integer" is exactly 1.
func formatParamSpacing(paramIdx, lastDeclaratorPos int, startCol uint32, currentNode, typeNode, declaratorNode *sitter.Node) []protocol.TextEdit {
	var result []protocol.TextEdit
	if paramIdx == 0 && currentNode.StartPoint().Column-startCol > 1 {
		result = append(
			result,
			protocol.TextEdit{
				Range: protocol.Range{
					Start: protocol.Position{
						Line:      uint(currentNode.StartPoint().Row),
						Character: uint(startCol) + 1,
					},
					End: protocol.Position{
						Line:      uint(currentNode.StartPoint().Row),
						Character: uint(currentNode.StartPoint().Column),
					},
				},
				NewText: "",
			},
		)
	} else if paramIdx > 0 {
		if int(typeNode.StartPoint().Column)-lastDeclaratorPos == 1 {
			result = append(
				result,
				protocol.TextEdit{
					Range: protocol.Range{
						Start: protocol.Position{
							Line:      uint(typeNode.StartPoint().Row),
							Character: uint(lastDeclaratorPos + 1),
						},
						End: protocol.Position{
							Line:      uint(typeNode.StartPoint().Row),
							Character: uint(lastDeclaratorPos + 1),
						},
					},
					NewText: " ",
				},
			)
		}
		if int(typeNode.StartPoint().Column)-lastDeclaratorPos > 2 {
			result = append(
				result,
				protocol.TextEdit{
					Range: protocol.Range{
						Start: protocol.Position{
							Line:      uint(typeNode.StartPoint().Row),
							Character: uint(lastDeclaratorPos + 1),
						},
						End: protocol.Position{
							Line:      uint(typeNode.StartPoint().Row),
							Character: uint(typeNode.StartPoint().Column),
						},
					},
					NewText: " ",
				},
			)
		}
	}
	return result
}
