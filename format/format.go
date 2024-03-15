package format

import (
	"strings"

	"github.com/kelly-lin/12d-lang-server/parser"
	"github.com/kelly-lin/12d-lang-server/protocol"
	sitter "github.com/smacker/go-tree-sitter"
)

// Get formatting edits for block indentations.
func GetIndentationEdits(node *sitter.Node) []protocol.TextEdit {
	result := []protocol.TextEdit{}
	stack := parser.NewStack()
	stack.Push(node)
	getIndentLevel := func(startNode *sitter.Node) int {
		indentLevel := 0
		currentNode := startNode.Parent()
		for currentNode != nil {
			if currentNode.Type() == "compound_statement" {
				indentLevel++
			}
			currentNode = currentNode.Parent()
		}
		return indentLevel
	}
	for stack.HasItems() {
		currentNode, _ := stack.Pop()
		nodeType := currentNode.Type()
		// if isSupportedIndentationNodeType(nodeType) {
		// HACK: we dont yet support formatting the children of for
		// statement nodes. Skip the iteration for now.
		// if nodeType == "declaration" && currentNode.Parent() != nil && currentNode.Parent().Type() == "for_statement" {
		// 	continue
		// }
		indentLevel := getIndentLevel(currentNode)
		targetIndentation := indentLevel * 4
		currentIndentation := currentNode.StartPoint().Column
		if nodeType == "if_statement" {
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
								Line:      uint(currentNode.EndPoint().Row),
								Character: uint(currentNode.StartPoint().Column),
							},
						},
						NewText: newText,
					},
				)
			}
		}
		if nodeType == "compound_statement" {
			if currentNode.EndPoint().Row > currentNode.StartPoint().Row {
				currIndent := currentNode.EndPoint().Column - 1
				if targetIndentation != int(currIndent) {
					if targetIndentation == 0 {
						result = append(
							result,
							protocol.TextEdit{
								Range: protocol.Range{
									Start: protocol.Position{
										Line:      uint(currentNode.EndPoint().Row),
										Character: 0,
									},
									End: protocol.Position{
										Line:      uint(currentNode.EndPoint().Row),
										Character: uint(currentNode.EndPoint().Column) - 1,
									},
								},
								NewText: "",
							},
						)
					} else {
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
										Line:      uint(currentNode.EndPoint().Row),
										Character: 0,
									},
									End: protocol.Position{
										Line:      uint(currentNode.EndPoint().Row),
										Character: uint(currentNode.EndPoint().Column) - 1,
									},
								},
								NewText: newText,
							},
						)
					}
				}
			}
		}
		if nodeType == "declaration" && currentNode.Parent().Type() != "for_statement" || nodeType == "while_statement" || nodeType == "function_definition" || nodeType == "for_statement" {
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
								Line:      uint(currentNode.EndPoint().Row),
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
		"compound_statement",
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
		result = append(result, formatDeclarationAndBodySpacing(bodyNode, funcDeclarationNode)...)
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
func formatDeclarationAndBodySpacing(bodyNode, funcDeclarationNode *sitter.Node) []protocol.TextEdit {
	if bodyNode.StartPoint().Row > funcDeclarationNode.EndPoint().Row {
		if bodyNode.StartPoint().Column > 0 {
			return []protocol.TextEdit{
				{
					Range: protocol.Range{
						Start: protocol.Position{
							Line:      1,
							Character: 0,
						},
						End: protocol.Position{
							Line:      1,
							Character: 2,
						},
					},
					NewText: "",
				},
			}
		}
		return []protocol.TextEdit{}
	}
	result := []protocol.TextEdit{}
	numSpaces := bodyNode.StartPoint().Column - funcDeclarationNode.EndPoint().Column
	if numSpaces != 1 {
		lineNum := uint(bodyNode.StartPoint().Row)
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
	paramIdx := 0
	numChildren := int(paramsNode.ChildCount())
	if numChildren == 0 {
		return []protocol.TextEdit{}
	}
	prevLine := -1
	var prevNode *sitter.Node
	for i := 0; i < numChildren; i++ {
		currentNode := paramsNode.Child(i)
		if currentNode.Type() == "parameter_declaration" {
			if prevNode != nil {
				result = append(result, formatParamSpacing(currentNode, prevNode)...)
			}

			if prevLine < int(currentNode.StartPoint().Row) {
				if int(currentNode.StartPoint().Row) == int(funcDeclarationNode.StartPoint().Row) {
					funcIdentifierNode := funcDeclarationNode.ChildByFieldName("declarator")
					if currentNode.StartPoint().Column-funcIdentifierNode.EndPoint().Column > 1 {
						result = append(
							result,
							protocol.TextEdit{
								Range: protocol.Range{
									Start: protocol.Position{
										Line:      uint(currentNode.StartPoint().Row),
										Character: uint(funcIdentifierNode.EndPoint().Column) + 1,
									},
									End: protocol.Position{
										Line:      uint(currentNode.StartPoint().Row),
										Character: uint(currentNode.StartPoint().Column),
									},
								},
								NewText: "",
							},
						)
					}
				} else {
					if currentNode.StartPoint().Column < 4 {
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
								NewText: "    ",
							},
						)
					}
				}
				prevLine = int(currentNode.StartPoint().Row)
			}

			typeNode := currentNode.ChildByFieldName("type")
			declaratorNode := currentNode.ChildByFieldName("declarator")
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
			// prevLine = uint32(typeNode.StartPoint().Row)
			prevNode = currentNode
			paramIdx++
		}
	}
	return result
}

// Get formatting edits for the spacing in between parameters. For example,
// The spacing of "Integer a," and "Integer b" "void Foo(Integer a, Integer b)".
// This function will return the edits so that the number of spaces between the
// comma after "a" and "Integer" is exactly 1.
func formatParamSpacing(currentNode, prevNode *sitter.Node) []protocol.TextEdit {
	var result []protocol.TextEdit
	currentTypeNode := currentNode.ChildByFieldName("type")
	prevDeclaratorEndCol := int(prevNode.ChildByFieldName("declarator").EndPoint().Column)
	currentTypeNodeStartCol := int(currentTypeNode.StartPoint().Column)
	if currentTypeNodeStartCol-prevDeclaratorEndCol == 1 {
		result = append(
			result,
			protocol.TextEdit{
				Range: protocol.Range{
					Start: protocol.Position{
						Line:      uint(currentTypeNode.StartPoint().Row),
						Character: uint(prevDeclaratorEndCol + 1),
					},
					End: protocol.Position{
						Line:      uint(currentTypeNode.StartPoint().Row),
						Character: uint(prevDeclaratorEndCol + 1),
					},
				},
				NewText: " ",
			},
		)
	}
	if currentTypeNodeStartCol-prevDeclaratorEndCol > 2 {
		result = append(
			result,
			protocol.TextEdit{
				Range: protocol.Range{
					Start: protocol.Position{
						Line:      uint(currentTypeNode.StartPoint().Row),
						Character: uint(prevDeclaratorEndCol + 1),
					},
					End: protocol.Position{
						Line:      uint(currentTypeNode.StartPoint().Row),
						Character: uint(currentTypeNode.StartPoint().Column),
					},
				},
				NewText: " ",
			},
		)
	}
	return result
}
