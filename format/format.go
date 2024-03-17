package format

import (
	"strings"

	"github.com/kelly-lin/12d-lang-server/parser/12dpl"
	"github.com/kelly-lin/12d-lang-server/protocol"
	sitter "github.com/smacker/go-tree-sitter"
)

const numSpaces = 4

// Get formatting edits for block indentations.
func GetIndentationEdits(node *sitter.Node) []protocol.TextEdit {
	result := []protocol.TextEdit{}
	stack := parser.NewStack()
	stack.Push(node)
	for stack.HasItems() {
		currentNode, _ := stack.Pop()
		nodeType := currentNode.Type()
		indentLevel := getIndentLevel(currentNode)
		targetIndentation := indentLevel * numSpaces
		if nodeType == "compound_statement" {
			result = append(result, indentCompoundStatementNode(currentNode, targetIndentation)...)
		}
		shouldIndentNode := nodeType == "declaration" && currentNode.Parent().Type() != "for_statement" || nodeType == "while_statement" || nodeType == "function_definition" || nodeType == "for_statement" || nodeType == "if_statement" && currentNode.Parent().Type() != "if_statement"
		if shouldIndentNode {
			result = append(result, indentNode(currentNode, targetIndentation)...)
		}
		for i := 0; i < int(currentNode.ChildCount()); i++ {
			stack.Push(currentNode.Child(i))
		}
	}
	return result
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
		result = append(result, formatFuncDeclarationAndBodySpacing(bodyNode, funcDeclarationNode)...)
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
func formatFuncDeclarationAndBodySpacing(bodyNode, funcDeclarationNode *sitter.Node) []protocol.TextEdit {
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

// Get the indentation level of the start node.
func getIndentLevel(startNode *sitter.Node) int {
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

// Build the indentation text with the given length.
func buildIndentText(length int) string {
	sb := strings.Builder{}
	for i := 0; i < length; i++ {
		sb.WriteRune(' ')
	}
	newText := sb.String()
	return newText
}

func indentCompoundStatementNode(currentNode *sitter.Node, targetIndentation int) []protocol.TextEdit {
	var result []protocol.TextEdit
	if currentNode.EndPoint().Row > currentNode.StartPoint().Row {
		currentIndentation := currentNode.EndPoint().Column - 1
		if targetIndentation != int(currentIndentation) {
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
				newText := buildIndentText(targetIndentation)
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
	return result
}

func indentNode(currentNode *sitter.Node, targetIndentation int) []protocol.TextEdit {
	var result []protocol.TextEdit
	currentIndentation := currentNode.StartPoint().Column
	if targetIndentation != int(currentIndentation) {
		newText := buildIndentText(targetIndentation)
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
	return result
}

func GetCallExpressionEdits(node *sitter.Node, sourceCode []byte) []protocol.TextEdit {
	result := []protocol.TextEdit{}
	stack := parser.NewStack()
	stack.Push(node)
	for stack.HasItems() {
		currentNode, _ := stack.Pop()
		nodeType := currentNode.Type()
		if nodeType == "call_expression" {
			argsNode := currentNode.ChildByFieldName("arguments")
			if int(argsNode.ChildCount()) == 2 && argsNode.Child(0).Content(sourceCode) == "(" && argsNode.Child(1).Content(sourceCode) == ")" {
				openingParenNode := argsNode.Child(0)
				closingParenNode := argsNode.Child(1)
				result = append(
					result,
					protocol.TextEdit{
						Range: protocol.Range{
							Start: protocol.Position{
								Line:      uint(openingParenNode.StartPoint().Row),
								Character: uint(openingParenNode.EndPoint().Column),
							},
							End: protocol.Position{
								Line:      uint(openingParenNode.StartPoint().Row),
								Character: uint(closingParenNode.StartPoint().Column),
							},
						},
						NewText: "",
					},
				)
			}
			var prevArgNode *sitter.Node
			var prevSeparatorNode *sitter.Node
			for i := 0; i < int(argsNode.ChildCount()); i++ {
				currentNode := argsNode.Child(i)
				isStartOrEndChar := currentNode.Content(sourceCode) == "(" || currentNode.Content(sourceCode) == ")"
				if isStartOrEndChar {
					continue
				}
				isSeparator := currentNode.Content(sourceCode) == ","
				isFirstArg := prevArgNode == nil
				if isSeparator {
					separatorNode := currentNode
					// Trim the space between the current separator node and
					// the end of the previous argument.
					if separatorNode.StartPoint().Column != prevArgNode.EndPoint().Column {
						result = append(
							result,
							protocol.TextEdit{
								Range: protocol.Range{
									Start: protocol.Position{
										Line:      uint(prevArgNode.StartPoint().Row),
										Character: uint(prevArgNode.EndPoint().Column),
									},
									End: protocol.Position{
										Line:      uint(prevArgNode.StartPoint().Row),
										Character: uint(separatorNode.StartPoint().Column),
									},
								},
								NewText: "",
							},
						)
					}
					prevSeparatorNode = currentNode
					continue
				}
				numOpeningParenFirstArgSpaces := currentNode.StartPoint().Column-argsNode.Child(0).StartPoint().Column != 1
				shouldTrimLeadingSpaceOfFirstArg := isFirstArg && numOpeningParenFirstArgSpaces
				if shouldTrimLeadingSpaceOfFirstArg {
					result = append(
						result,
						protocol.TextEdit{
							Range: protocol.Range{
								Start: protocol.Position{
									Line:      uint(argsNode.Child(0).EndPoint().Row),
									Character: uint(argsNode.Child(0).EndPoint().Column),
								},
								End: protocol.Position{
									Line:      uint(argsNode.Child(0).EndPoint().Row),
									Character: uint(currentNode.StartPoint().Column),
								},
							},
							NewText: "",
						},
					)
				}
				if !isFirstArg && prevSeparatorNode != nil {
					// Trim space between the start of the argument node and the
					// previous separator node.
					if currentNode.StartPoint().Column-prevSeparatorNode.StartPoint().Column != 2 {
						result = append(
							result,
							protocol.TextEdit{
								Range: protocol.Range{
									Start: protocol.Position{
										Line:      uint(prevArgNode.StartPoint().Row),
										Character: uint(prevArgNode.EndPoint().Column) + 1,
									},
									End: protocol.Position{
										Line:      uint(currentNode.StartPoint().Row),
										Character: uint(currentNode.StartPoint().Column),
									},
								},
								NewText: " ",
							},
						)
					}
				}
				prevArgNode = currentNode
			}
		}
		for i := 0; i < int(currentNode.ChildCount()); i++ {
			stack.Push(currentNode.Child(i))
		}
	}
	return result
}
