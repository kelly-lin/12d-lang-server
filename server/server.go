package server

import (
	"bufio"
	"context"
	"encoding/json"
	"errors"
	"fmt"
	"io"
	"io/fs"
	"os"
	"path/filepath"
	"regexp"
	"strconv"
	"strings"

	"github.com/kelly-lin/12d-lang-server/lang"
	"github.com/kelly-lin/12d-lang-server/parser"
	"github.com/kelly-lin/12d-lang-server/protocol"
	sitter "github.com/smacker/go-tree-sitter"
)

const contentLengthHeaderName = "Content-Length"

// Unhandled LSP method error.
var ErrUnhandledMethod = errors.New("unhandled method")

var supportedIndentationNodeTypes = []string{"declaration", "for_statement", "switch_statement", "while_statement", "if_statement", "function_definition"}

type LangCompletions struct {
	Keyword []protocol.CompletionItem
	Lib     []protocol.CompletionItem
	Type    []protocol.CompletionItem
}

var BuiltInLangCompletions LangCompletions = LangCompletions{
	Keyword: lang.KeywordCompletionItems,
	Lib:     lang.LibCompletionItems,
	Type:    lang.TypeCompletionItems,
}

// Creates a new language server. The logger function parameter specifies the
// function to call for logging. If the logger is nil, will default to a
// function that does not log anything. The includes directory is an absolute path.
func NewServer(includesDir string, builtInCompletions *LangCompletions, logger func(msg string)) Server {
	serverLogger := func(msg string) {}
	if logger != nil {
		serverLogger = logger
	}
	s := Server{
		documents:   make(map[string]Document),
		logger:      serverLogger,
		includesDir: includesDir,
	}
	if builtInCompletions != nil {
		s.builtInCompletions = *builtInCompletions
	}
	// TODO: hard coding in an includes directory for now. Need to move this to
	// config in client and expose this via an option on the command line.
	if s.includesDir != "" {
		filesystem := os.DirFS(s.includesDir)
		if includeFiles, err := fs.Glob(filesystem, "*.h"); err == nil {
			for _, includeFile := range includeFiles {
				filepath := filepath.Join(s.includesDir, includeFile)
				contents, err := os.ReadFile(filepath)
				if err != nil {
					continue
				}
				// TODO: how do we handle this error? Should we signal to
				// the user that we had issues updating the file?
				_ = s.setDocument(protocol.URI(filepath), string(contents))
			}
		}
	}
	return s
}

// Language server.
type Server struct {
	documents          map[string]Document
	logger             func(msg string)
	includesDir        string
	builtInCompletions LangCompletions
}

// Serve reads JSONRPC from the reader, processes the message and responds by
// writing to writer.
func (s *Server) Serve(rd io.Reader, w io.Writer) error {
	reader := bufio.NewReader(rd)
	for {
		s.logger("\n------------------------------------------------------------------\nreading message...\n")
		msg, err := readMessage(reader)
		if err != nil {
			s.logger(fmt.Sprintf("[ERROR] %s\n", err.Error()))
			return err
		}
		s.logger(fmt.Sprintf("[REQUEST]\n%s\n", stringifyRequestMessage(msg)))

		if msg.Method == "exit" {
			return nil
		}

		content, numBytes, err := s.handleMessage(msg)
		if err != nil {
			s.logger(fmt.Sprintf("[ERROR] could not handle message: %s\n", err))
		}
		if numBytes == 0 {
			s.logger("no bytes to reply, not responding")
			continue
		}
		contentBytes, err := json.Marshal(content)
		if err != nil {
			s.logger("could not marshal contents")
			continue
		}
		resMsg := ToProtocolMessage(contentBytes)
		s.logger(fmt.Sprintf("[RESPONSE] \n%s", resMsg))
		if _, err = fmt.Fprint(w, resMsg); err != nil {
			s.logger(fmt.Sprintf("could print message to output %v: %s\n", msg, err))
			continue
		}
	}
}

// Read LSP messages from the reader and return the unmarshalled request
// message.
func readMessage(r *bufio.Reader) (protocol.RequestMessage, error) {
	message := protocol.RequestMessage{}
	var contentLength int64
	for {
		line, err := r.ReadString('\n')
		if err != nil {
			return message, fmt.Errorf("could not read line: %s", err)
		}
		line = strings.TrimSpace(line)
		if line == "" {
			break
		}
		colonIndex := strings.IndexRune(line, ':')
		if colonIndex == -1 {
			return message, fmt.Errorf("could not find colon delimiter in header")
		}
		name := line[:colonIndex]
		value := strings.TrimSpace(line[colonIndex+1:])
		if name == "Content-Length" {
			if contentLength, err = strconv.ParseInt(value, 10, 64); err != nil {
				return message, fmt.Errorf("failed to parse content length: %s", err)
			}
		}
	}

	content := make([]byte, contentLength)
	_, err := io.ReadFull(r, content)
	if err != nil {
		return message, fmt.Errorf("failed to read content: %s", err)
	}

	if err := json.Unmarshal(content, &message); err != nil {
		return message, fmt.Errorf("failed to unmarshal message: %s", err)
	}
	return message, nil
}

// Handles the request message and returns the response, number of bytes in the
// response and error. Notifications will return 0 bytes for the response.
func (s *Server) handleMessage(msg protocol.RequestMessage) (protocol.ResponseMessage, int, error) {
	// Not going to handle any LSP version specific methods (methods prefixed
	// with "$/") for now.
	if matched, _ := regexp.MatchString(`^\$\/.+`, msg.Method); matched {
		err := protocol.ResponseError{Code: -32601, Message: "unhandled method"}
		return protocol.ResponseMessage{ID: msg.ID, Error: &err}, 0, nil
	}
	switch msg.Method {
	case "initialize":
		result := protocol.InitializeResult{
			Capabilities: newServerCapabilities(),
		}
		resultBytes, err := json.Marshal(result)
		if err != nil {
			return protocol.ResponseMessage{}, 0, err
		}
		return protocol.ResponseMessage{
				ID:     msg.ID,
				Result: json.RawMessage(resultBytes),
			},
			len(resultBytes),
			nil

	case "textDocument/completion":
		var params protocol.CompletionParams
		if err := json.Unmarshal(msg.Params, &params); err != nil {
			return newNullResponseMessage(msg.ID), len(protocol.NullResult), err
		}
		doc, ok := s.documents[params.TextDocument.URI]
		if !ok {
			return newNullResponseMessage(msg.ID), len(protocol.NullResult), errors.New("source node not found")
		}
		rootNode := doc.RootNode
		sourceCode := doc.SourceCode
		items := getCompletionItems(rootNode, sourceCode, params.Position, s.builtInCompletions)
		resultBytes, err := json.Marshal(items)
		if err != nil {
			return protocol.ResponseMessage{}, 0, err
		}
		return protocol.ResponseMessage{
				ID:     msg.ID,
				Result: json.RawMessage(resultBytes),
			},
			len(resultBytes),
			nil

	case "textDocument/hover":
		var params protocol.HoverParams
		if err := json.Unmarshal(msg.Params, &params); err != nil {
			return newNullResponseMessage(msg.ID), len(protocol.NullResult), err
		}
		doc, ok := s.documents[params.TextDocument.URI]
		if !ok {
			return newNullResponseMessage(msg.ID), len(protocol.NullResult), errors.New("source node not found")
		}
		rootNode := doc.RootNode
		sourceCode := doc.SourceCode
		identifierNode, err := parser.FindIdentifierNode(rootNode, params.Position.Line, params.Position.Character)
		if err != nil {
			return newNullResponseMessage(msg.ID), len(protocol.NullResult), err
		}
		identifier := identifierNode.Content(sourceCode)
		if errors.Is(err, parser.ErrNoDefinition) {
			return newNullResponseMessage(msg.ID), len(protocol.NullResult), nil
		}
		if err != nil {
			return newNullResponseMessage(msg.ID), len(protocol.NullResult), err
		}
		contents := getHoverContents(identifierNode, identifier, params.TextDocument.URI, s.documents, s.includesDir)
		if len(contents) == 0 {
			return newNullResponseMessage(msg.ID), len(protocol.NullResult), nil
		}
		result := protocol.Hover{Contents: contents}
		resultBytes, err := json.Marshal(result)
		if err != nil {
			return newNullResponseMessage(msg.ID), len(protocol.NullResult), err
		}
		return protocol.ResponseMessage{
				ID:     msg.ID,
				Result: json.RawMessage(resultBytes),
			},
			len(resultBytes),
			nil

	case "shutdown":
		return newNullResponseMessage(msg.ID), len(protocol.NullResult), nil

	case "textDocument/didOpen":
		var params protocol.DidOpenTextDocumentParams
		if err := json.Unmarshal(msg.Params, &params); err != nil {
			return protocol.ResponseMessage{}, 0, err
		}
		if params.TextDocument.LanguageID != "12dpl" {
			return protocol.ResponseMessage{}, 0, fmt.Errorf("unhandled language %s, expected 12dpl", params.TextDocument.LanguageID)
		}
		if err := s.setDocument(params.TextDocument.URI, params.TextDocument.Text); err != nil {
			return protocol.ResponseMessage{}, 0, err
		}
		return protocol.ResponseMessage{}, 0, nil

	case "textDocument/didChange":
		var params protocol.DidChangeTextDocumentParams
		if err := json.Unmarshal(msg.Params, &params); err != nil {
			return protocol.ResponseMessage{}, 0, err
		}
		// The server currently only supports a full document sync.
		if err := s.setDocument(params.TextDocument.URI, params.ContentChanges[len(params.ContentChanges)-1].Text); err != nil {
			return protocol.ResponseMessage{}, 0, err
		}
		return protocol.ResponseMessage{}, 0, nil

	case "textDocument/formatting":
		var params protocol.DocumentFormattingParams
		if err := json.Unmarshal(msg.Params, &params); err != nil {
			return protocol.ResponseMessage{}, 0, err
		}
		doc, ok := s.documents[params.TextDocument.URI]
		if !ok {
			return newNullResponseMessage(msg.ID), len(protocol.NullResult), errors.New("source node not found")
		}
		var edits []protocol.TextEdit = []protocol.TextEdit{}
		stack := parser.NewStack()
		stack.Push(doc.RootNode)
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
					edits = append(
						edits,
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
		editsBytes, err := json.Marshal(edits)
		if err != nil {
			return protocol.ResponseMessage{}, 0, err
		}
		return protocol.ResponseMessage{
				ID:     msg.ID,
				Result: json.RawMessage(editsBytes),
			},
			len(editsBytes),
			nil

	case "textDocument/definition":
		var params protocol.DefinitionParams
		if err := json.Unmarshal(msg.Params, &params); err != nil {
			return protocol.ResponseMessage{}, 0, err
		}
		doc, ok := s.documents[params.TextDocument.URI]
		if !ok {
			return newNullResponseMessage(msg.ID), len(protocol.NullResult), errors.New("source node not found")
		}
		rootNode := doc.RootNode
		sourceCode := doc.SourceCode
		identifierNode, err := parser.FindIdentifierNode(rootNode, params.Position.Line, params.Position.Character)
		if errors.Is(err, parser.ErrNoDefinition) {
			return newNullResponseMessage(msg.ID), len(protocol.NullResult), nil
		}
		if err != nil {
			return newNullResponseMessage(msg.ID), len(protocol.NullResult), err
		}
		identifier := identifierNode.Content(sourceCode)
		def, err := findDefinition(identifierNode, identifier, params.TextDocument.URI, s.documents, s.includesDir)
		if err != nil {
			return newNullResponseMessage(msg.ID), len(protocol.NullResult), nil
		}
		location := protocol.Location{
			URI:   def.URI,
			Range: ToProtocolRange(def.Range),
		}
		locationBytes, err := json.Marshal(location)
		if err != nil {
			return protocol.ResponseMessage{}, 0, err
		}
		return protocol.ResponseMessage{
				ID:     msg.ID,
				Result: json.RawMessage(locationBytes),
			},
			len(locationBytes),
			nil

	case "textDocument/references":
		var params protocol.ReferenceParams
		if err := json.Unmarshal(msg.Params, &params); err != nil {
			return protocol.ResponseMessage{}, 0, err
		}
		doc, ok := s.documents[params.TextDocument.URI]
		if !ok {
			return newNullResponseMessage(msg.ID), len(protocol.NullResult), errors.New("source node not found")
		}
		rootNode := doc.RootNode
		sourceCode := doc.SourceCode
		identifierNode, err := parser.FindIdentifierNode(rootNode, params.Position.Line, params.Position.Character)
		if err != nil {
			return newNullResponseMessage(msg.ID), len(protocol.NullResult), err
		}
		identifier := identifierNode.Content(sourceCode)
		def, err := findDefinition(identifierNode, identifier, params.TextDocument.URI, s.documents, s.includesDir)
		if err != nil {
			if _, ok := lang.Lib[identifier]; !ok {
				return newNullResponseMessage(msg.ID), len(protocol.NullResult), nil
			}
		}
		locations := []protocol.Location{}
		if params.Context.IncludeDeclaration && err == nil {
			declarationLocation := protocol.Location{
				URI:   def.URI,
				Range: ToProtocolRange(def.Range),
			}
			locations = append(locations, declarationLocation)
		}
		scopeNode := rootNode
		if err == nil {
			scopeNode = getScopeNode(def.Node)
		}
		// For all children and their children inside of scope, if there is an
		// identifier who's value is equal to our definition identifier, get it's
		// location.
		referenceNodes := getReferenceNodes(scopeNode, def.Node, identifier, sourceCode)
		referenceLocations := ToLocations(referenceNodes, params.TextDocument.URI)
		locations = append(locations, referenceLocations...)
		locationsBytes, err := json.Marshal(locations)
		if err != nil {
			return protocol.ResponseMessage{}, 0, err
		}
		return protocol.ResponseMessage{
				ID:     msg.ID,
				Result: json.RawMessage(locationsBytes),
			},
			len(locationsBytes),
			nil

	case "textDocument/rename":
		var params protocol.RenameParams
		if err := json.Unmarshal(msg.Params, &params); err != nil {
			return protocol.ResponseMessage{}, 0, err
		}
		doc, ok := s.documents[params.TextDocument.URI]
		if !ok {
			return newNullResponseMessage(msg.ID), len(protocol.NullResult), errors.New("source node not found")
		}
		rootNode := doc.RootNode
		sourceCode := doc.SourceCode
		identifierNode, err := parser.FindIdentifierNode(rootNode, params.Position.Line, params.Position.Character)
		if err != nil {
			return newNullResponseMessage(msg.ID), len(protocol.NullResult), err
		}
		identifier := identifierNode.Content(sourceCode)
		def, err := findDefinition(identifierNode, identifier, params.TextDocument.URI, s.documents, s.includesDir)
		if err != nil {
			return newNullResponseMessage(msg.ID), len(protocol.NullResult), err
		}
		scopeNode := rootNode
		if err == nil {
			scopeNode = getScopeNode(def.Node)
		}
		referenceNodes := getReferenceNodes(scopeNode, def.Node, identifier, sourceCode)
		nodes := []*sitter.Node{def.Node}
		nodes = append(nodes, referenceNodes...)
		ranges := ToRanges(nodes)
		workspaceEdit := protocol.WorkspaceEdit{
			Changes: map[string][]protocol.TextEdit{},
		}
		for _, textRange := range ranges {
			workspaceEdit.Changes[params.TextDocument.URI] = append(
				workspaceEdit.Changes[params.TextDocument.URI],
				protocol.TextEdit{Range: textRange, NewText: params.NewName},
			)
		}
		editsBytes, err := json.Marshal(workspaceEdit)
		if err != nil {
			return protocol.ResponseMessage{}, 0, err
		}
		return protocol.ResponseMessage{
				ID:     msg.ID,
				Result: json.RawMessage(editsBytes),
			},
			len(editsBytes),
			nil

	case "initialized":
		return protocol.ResponseMessage{}, 0, nil

	default:
		return protocol.ResponseMessage{}, 0, ErrUnhandledMethod
	}
}

// Traverse up the tree and find the node which represents the scope of the
// provided identifier node.
func getScopeNode(identifierNode *sitter.Node) *sitter.Node {
	result := identifierNode.Parent()
	for result.Parent() != nil {
		if result.Type() == "function_definition" && isParamDeclaration(identifierNode) {
			break
		}
		if result.Type() == "compound_statement" && result.Parent().Type() != "source_file" {
			break
		}
		if result.Parent() == nil {
			break
		}
		result = result.Parent()
	}
	return result
}

// Convert the nodes into LSP protocol locations.
func ToLocations(referenceNodes []*sitter.Node, uri string) []protocol.Location {
	var locations []protocol.Location
	for _, node := range referenceNodes {
		locations = append(
			locations,
			protocol.Location{
				URI: uri,
				Range: protocol.Range{
					Start: protocol.Position{
						Line:      uint(node.StartPoint().Row),
						Character: uint(node.StartPoint().Column),
					},
					End: protocol.Position{
						Line:      uint(node.EndPoint().Row),
						Character: uint(node.EndPoint().Column),
					},
				},
			},
		)
	}
	return locations
}

// Convert the nodes into LSP protocol ranges.
func ToRanges(nodes []*sitter.Node) []protocol.Range {
	var locations []protocol.Range
	for _, node := range nodes {
		locations = append(
			locations,
			protocol.Range{
				Start: protocol.Position{
					Line:      uint(node.StartPoint().Row),
					Character: uint(node.StartPoint().Column),
				},
				End: protocol.Position{
					Line:      uint(node.EndPoint().Row),
					Character: uint(node.EndPoint().Column),
				},
			},
		)
	}
	return locations
}

func getReferenceNodes(scopeNode, declarationNode *sitter.Node, identifier string, sourceCode []byte) []*sitter.Node {
	var result []*sitter.Node
	stack := parser.NewStack()
	stack.Push(scopeNode)
	for stack.HasItems() {
		currNode, _ := stack.Pop()
		if currNode != declarationNode &&
			currNode.Type() == "identifier" &&
			currNode.Content(sourceCode) == identifier {
			result = append(result, currNode)
		}
		for i := 0; i < int(currNode.ChildCount()); i++ {
			stack.Push(currNode.Child(i))
		}
	}
	return result
}

// Update the document stored on the server identified by the uri with provided
// content.
func (s *Server) setDocument(uri string, content string) error {
	rootNode, err := sitter.ParseCtx(context.Background(), []byte(content), parser.GetLanguage())
	if err != nil {
		return err
	}
	s.documents[uri] = Document{RootNode: rootNode, SourceCode: []byte(content)}
	return nil
}

// Gets the completion items for the node given by position.
func getCompletionItems(rootNode *sitter.Node, sourceCode []byte, position protocol.Position, builtInCompletions LangCompletions) []protocol.CompletionItem {
	var result []protocol.CompletionItem

	// Depth first search the deepest node described by position.
	stack := parser.NewStack()
	stack.Push(rootNode)
	var nearestNode *sitter.Node
	for stack.HasItems() {
		currentNode, err := stack.Pop()
		if err != nil {
			continue
		}
		if currentNode.StartPoint().Row == uint32(position.Line) &&
			uint(currentNode.StartPoint().Column) <= position.Character &&
			position.Character <= uint(currentNode.EndPoint().Column) {
			nearestNode = currentNode
		}
		for i := 0; i < int(currentNode.ChildCount()); i++ {
			stack.Push(currentNode.Child(i))
		}
	}
	if nearestNode == nil {
		return nil
	}

	// We might get a node which has a parent with the same row and col numbers
	// like below:
	//   (compound_statement [0, 12] - [2, 1]
	//     (ERROR [1, 4] - [1, 5]
	//       (identifier [1, 4] - [1, 5]))
	// To handle this, walk up the parents and find the nearest parent which has
	// the same coordinates and set it as the nearest node instead.
	for nearestNode.Parent() != nil {
		currentNode := nearestNode.Parent()
		if currentNode.StartPoint().Row == nearestNode.StartPoint().Row &&
			currentNode.StartPoint().Column == nearestNode.StartPoint().Column &&
			currentNode.EndPoint().Row == nearestNode.EndPoint().Row &&
			currentNode.EndPoint().Column == nearestNode.EndPoint().Column {
			nearestNode = currentNode
		} else {
			break
		}
	}
	isFuncIdentifier := nearestNode.Parent() != nil &&
		nearestNode.Parent().Parent() != nil &&
		nearestNode.Type() == "identifier" &&
		nearestNode.Parent().Parent().Type() == "source_file"
	if isFuncIdentifier {
		return nil
	}
	isParameterDeclaration := nearestNode.Parent() != nil &&
		nearestNode.Parent().Type() == "parameter_declaration"
	if isParameterDeclaration {
		return nil
	}

	isCursorOnDeclaration := func() bool {
		if parent := nearestNode.Parent(); parent != nil && nearestNode.Parent().Type() == "declaration" {
			return true
		}
		return false
	}
	// We are typing in a declaration identifier, do not provide completion.
	if isCursorOnDeclaration() {
		return nil
	}

	var reachableDeclarators []*sitter.Node
	// Walk up the tree and look for reachable declarators.
	currentNode := nearestNode
	for currentNode.Parent() != nil {
		currentNode = currentNode.Parent()
		for i := 0; i < int(currentNode.ChildCount()); i++ {
			currentChild := currentNode.Child(i)
			if currentChild.StartPoint().Row >= nearestNode.StartPoint().Row {
				break
			}
			if currentChild.Type() == "declaration" {
				reachableDeclarators = append(reachableDeclarators, currentChild)
			}
			if currentChild.Type() == "function_definition" {
				reachableDeclarators = append(reachableDeclarators, currentChild)
			}
			// TODO: include completions for include files.
		}
	}
	var declarations []protocol.CompletionItem
	for _, declaratorNode := range reachableDeclarators {
		if declaratorNode.Type() == "declaration" {
			for i := 0; i < int(declaratorNode.ChildCount()); i++ {
				currentChild := declaratorNode.Child(i)
				if currentChild.Type() == "identifier" {
					if varType, err := getDefinitionType(currentChild, sourceCode); err == nil {
						declarations = append(declarations, protocol.CompletionItem{
							Label:  currentChild.Content(sourceCode),
							Kind:   protocol.GetCompletionItemKind(protocol.CompletionItemKindVariable),
							Detail: varType,
						})
					}
				}
				if currentChild.Type() == "init_declarator" {
					if varType, err := getDefinitionType(currentChild.ChildByFieldName("declarator"), sourceCode); err == nil {
						declarations = append(declarations, protocol.CompletionItem{
							Label:  currentChild.ChildByFieldName("declarator").Content(sourceCode),
							Kind:   protocol.GetCompletionItemKind(protocol.CompletionItemKindVariable),
							Detail: varType,
						})
					}
				}
			}
		}
		if declaratorNode.Type() == "function_definition" {
			identifier := declaratorNode.ChildByFieldName("declarator").ChildByFieldName("declarator").Content(sourceCode)
			if varType, declaration, doc, err := getFuncDocComponents(declaratorNode, sourceCode); err == nil {
				item := protocol.CompletionItem{
					Label:  identifier,
					Detail: fmt.Sprintf("%s %s", varType, declaration),
					Kind:   protocol.GetCompletionItemKind(protocol.CompletionItemKindFunction),
				}
				if doc != "" {
					item.Documentation = &protocol.MarkupContent{
						Kind:  protocol.MarkupKindPlainText,
						Value: doc,
					}
				}
				declarations = append(declarations, item)
			}
		}
	}

	if funcDefNode := getParentFuncDefinitionNode(nearestNode); funcDefNode != nil &&
		funcDefNode.ChildByFieldName("declarator").ChildByFieldName("parameters") != nil {
		paramsNode := funcDefNode.ChildByFieldName("declarator").ChildByFieldName("parameters")
		paramCompletions := getFuncParamCompletions(paramsNode, sourceCode)
		declarations = append(declarations, paramCompletions...)
	}

	// TODO: refactor this, especially the parent chaining.
	isInFuncParamList := nearestNode.Parent() != nil &&
		nearestNode.Parent().Parent() != nil &&
		nearestNode.Parent().Parent().Type() == "source_file" &&
		nearestNode.Parent().ChildCount() > 1 &&
		nearestNode.Parent().Child(0).Type() == "primitive_type" &&
		nearestNode.Parent().Child(1).Type() == "identifier"
	isRootDeclaration := nearestNode.Type() == "source_file"
	isInsideFuncBody := nearestNode.Parent() != nil && nearestNode.Parent().Type() == "compound_statement"
	isIdentifier := nearestNode.Type() == "identifier"
	switch {
	case isRootDeclaration, isInFuncParamList:
		result = append(result, builtInCompletions.Type...)
	case nearestNode.Parent() != nil && nearestNode.Parent().Type() == "init_declarator":
		result = append(result, declarations...)
		result = append(result, builtInCompletions.Lib...)
	case isInsideFuncBody:
		result = append(result, declarations...)
		result = append(result, builtInCompletions.Keyword...)
		result = append(result, builtInCompletions.Lib...)
		result = append(result, builtInCompletions.Type...)
	case isIdentifier:
		result = append(result, declarations...)
		result = append(result, builtInCompletions.Keyword...)
		result = append(result, builtInCompletions.Lib...)
		result = append(result, builtInCompletions.Type...)
	default:
		result = append(result, declarations...)
		result = append(result, builtInCompletions.Keyword...)
		result = append(result, builtInCompletions.Type...)
	}
	return result
}

// Traverse up start node's parents and return the first which is of type
// "function definition".
func getParentFuncDefinitionNode(startNode *sitter.Node) *sitter.Node {
	var result *sitter.Node
	currentNode := startNode
	for currentNode.Parent() != nil {
		currentNode = currentNode.Parent()
		if currentNode.Type() == "function_definition" {
			result = currentNode
			break
		}
	}
	return result
}

func getFuncParamCompletions(paramsNode *sitter.Node, sourceCode []byte) []protocol.CompletionItem {
	var result []protocol.CompletionItem
	for i := 0; i < int(paramsNode.ChildCount()); i++ {
		currentChild := paramsNode.Child(i)
		if currentChild.Type() == "parameter_declaration" {
			varType := currentChild.ChildByFieldName("type").Content(sourceCode)
			identifier := currentChild.ChildByFieldName("declarator").Content(sourceCode)
			item := protocol.CompletionItem{
				Label:  identifier,
				Detail: fmt.Sprintf("(parameter) %s", varType),
				Kind:   protocol.GetCompletionItemKind(protocol.CompletionItemKindVariable),
			}
			result = append(result, item)
		}
	}
	return result
}

// Gets the hover items for the provided node and identifier. The hover items
// are strings of documentation to send to the client.
func getHoverContents(identifierNode *sitter.Node, identifier string, uri string, documents map[string]Document, includesDir string) []string {
	doc, ok := documents[uri]
	if !ok {
		return []string{}
	}

	var result []string
	if identifierNode.Parent().Type() == "call_expression" {
		result = getFuncHoverContents(identifierNode, identifier, uri, documents, includesDir, doc.SourceCode)
		return result
	}

	def, err := findDefinition(identifierNode, identifier, uri, documents, includesDir)
	node := def.Node
	if err != nil || node == nil || node.Type() != "identifier" {
		return []string{}
	}
	sourceCode := documents[def.URI].SourceCode
	if isFuncDefinition(node) {
		funcDefNode := node.Parent().Parent()
		if varType, declaration, desc, err := getFuncDocComponents(funcDefNode, sourceCode); err == nil {
			result = append(result, createHoverDeclarationDocString(varType, declaration, desc, ""))
			return result
		}
	}

	nodeType, err := getDefinitionType(node, sourceCode)
	if err != nil {
		return []string{}
	}
	prefix := getHoverPrefix(node)
	hoverIdentifier := getHoverIdentifier(node, sourceCode)
	switch node.Parent().Type() {
	case "array_declarator":
		nodeType = strings.TrimSuffix(nodeType, "[]")
		identifier := hoverIdentifier + "[]"
		if node.Parent().Parent().Type() == "pointer_declarator" {
			identifier = fmt.Sprintf("&%s", identifier)
		}
		result = append(result, createHoverDeclarationDocString(nodeType, identifier, "", prefix))

	case "preproc_def":
		signature := strings.TrimSpace(node.Parent().Content(sourceCode))
		result = append(result, protocol.CreateDocMarkdownString(signature, ""))

	default:
		result = append(result, createHoverDeclarationDocString(nodeType, hoverIdentifier, "", prefix))
	}
	return result
}

// Find the definition of the identifier node which is a function call
// expression and return the documentation contents.
func getFuncHoverContents(identifierNode *sitter.Node, identifier string, uri string, documents map[string]Document, includesDir string, sourceCode []byte) []string {
	var contents []string
	def, err := findDefinition(identifierNode, identifier, uri, documents, includesDir)
	// We cannot find the definition, try find it in the library items.
	if err != nil {
		libItems, ok := lang.Lib[identifier]
		if !ok || len(libItems) == 0 {
			return []string{}
		}
		contents = filterLibItems(identifierNode, libItems, uri, documents, includesDir)
		return contents
	}
	// We found the definition, get the signature.
	node := def.Node
	if isFuncDefinition(node) {
		funcDefNode := node.Parent().Parent()
		if varType, declaration, desc, err := getFuncDocComponents(funcDefNode, sourceCode); err == nil {
			contents = append(contents, createHoverDeclarationDocString(varType, declaration, desc, ""))
			return contents
		}
	}
	return contents
}

// Hover documentation can have a prefix to give more context on the identifier,
// for example an identifier can be a parameter which should have a prefix of
// "parameter".
func getHoverPrefix(node *sitter.Node) string {
	result := ""
	if isParamDeclaration(node) {
		result = "parameter"
	}
	return result
}

// The identifier that is shown on hover documentation.
func getHoverIdentifier(node *sitter.Node, sourceCode []byte) string {
	result := node.Content(sourceCode)
	if isParamDeclaration(node) {
		if node.Parent().Type() == "pointer_declarator" {
			result = node.Parent().Content(sourceCode)
		}
	}
	return result
}

// Formats the function declaration for display as documentation.
func formatFuncDeclaration(funcDefNode *sitter.Node, sourceCode []byte) (string, error) {
	declaratorNode := funcDefNode.ChildByFieldName("declarator")
	if declaratorNode == nil {
		return "", errors.New("declarator not found")
	}
	identifierNode := declaratorNode.ChildByFieldName("declarator")
	if identifierNode == nil {
		return "", errors.New("identifier not found")
	}
	paramsNode := declaratorNode.ChildByFieldName("parameters")
	if paramsNode == nil {
		return "", errors.New("parameters node not found")
	}
	params := ""
	var paramItems []string
	for i := 0; i < int(paramsNode.ChildCount()); i++ {
		paramNode := paramsNode.Child(i)
		if paramNode.Type() != "parameter_declaration" {
			continue
		}
		typeNode := paramNode.ChildByFieldName("type")
		if typeNode == nil {
			return "", fmt.Errorf("type node not found for parameter %d", i)
		}
		identifierNode := paramNode.ChildByFieldName("declarator")
		if identifierNode == nil {
			return "", fmt.Errorf("identifier node not found for parameter %d", i)
		}
		paramItems = append(paramItems, fmt.Sprintf("%s %s", typeNode.Content(sourceCode), identifierNode.Content(sourceCode)))
	}
	for i, item := range paramItems {
		if i == 0 {
			params = item
		} else {
			params = fmt.Sprintf("%s, %s", params, item)
		}
	}
	return fmt.Sprintf("%s(%s)", identifierNode.Content(sourceCode), params), nil
}

// Formats the raw text from a comment node for display as documentation. This
// includes trimming spaces and removing comment characters "//" and "/*" "*/".
func formatDescComment(desc string) string {
	result := strings.TrimPrefix(desc, "/*")
	result = strings.TrimSuffix(result, "*/")
	descLines := strings.Split(result, "\n")
	var newLines []string
	for _, line := range descLines {
		newLine := strings.TrimPrefix(line, "//")
		newLine = strings.TrimSpace(newLine)
		newLines = append(newLines, newLine)
	}
	result = strings.Join(newLines, "\n")
	result = strings.TrimSpace(result)
	return result
}

// Gets the type, declaration and description from the function definition node.
// Returns error if any of the components cannot be found.
func getFuncDocComponents(funcDefNode *sitter.Node, sourceCode []byte) (string, string, string, error) {
	typeNode := funcDefNode.ChildByFieldName("type")
	if typeNode == nil {
		return "", "", "", errors.New("type node not found")
	}
	varType := typeNode.Content(sourceCode)
	declaration, err := formatFuncDeclaration(funcDefNode, sourceCode)
	if err != nil {
		return "", "", "", fmt.Errorf("could not format function declaration: %w", err)
	}
	desc := ""
	docNode := funcDefNode.PrevSibling()
	if docNode != nil && docNode.Type() == "comment" {
		isDocNodeAboveDefinition := funcDefNode.StartPoint().Row-1 == docNode.EndPoint().Row
		if isDocNodeAboveDefinition {
			desc = docNode.Content(sourceCode)
			desc = formatDescComment(desc)
		}
	}
	return varType, declaration, desc, nil
}

// Returns true if the provided identifier node is for a function definition.
func isFuncDefinition(node *sitter.Node) bool {
	if funcDefNode := node.Parent().Parent(); funcDefNode != nil && funcDefNode.Type() == "function_definition" {
		return true
	}
	return false
}

// Gets the definition type of the provided identifier node. For example, a node
// which represents: "Integer One = 1;" where node has content "One", will
// return "Integer".
func getDefinitionType(node *sitter.Node, sourceCode []byte) (string, error) {
	varType := ""
	if node.Parent().Type() == "preproc_def" && node.Parent().ChildByFieldName("value").Child(0) != nil {
		if node.Parent().ChildByFieldName("value").Child(0).Type() == "string_literal" {
			return "Text", nil
		}
		if node.Parent().ChildByFieldName("value").Child(0).Type() == "number_literal" {
			return "Integer", nil
		}
	}
	if node.Parent().Type() == "declaration" && node.Parent().ChildByFieldName("type") != nil {
		typeNode := node.Parent().ChildByFieldName("type")
		varType = typeNode.Content(sourceCode)
	}
	if node.Parent().Type() == "init_declarator" && node.Parent().Parent().ChildByFieldName("type") != nil {
		typeNode := node.Parent().Parent().ChildByFieldName("type")
		varType = typeNode.Content(sourceCode)
	}
	if node.Parent().Type() == "parameter_declaration" {
		typeNode := node.Parent().ChildByFieldName("type")
		varType = typeNode.Content(sourceCode)
	}
	if node.Parent().Type() == "pointer_declarator" && node.Parent().Parent().ChildByFieldName("type") != nil {
		typeNode := node.Parent().Parent().ChildByFieldName("type")
		varType = typeNode.Content(sourceCode)
	}
	if node.Parent().Type() == "function_declarator" && node.Parent().Parent().ChildByFieldName("type") != nil {
		typeNode := node.Parent().Parent().ChildByFieldName("type")
		varType = typeNode.Content(sourceCode)
	}
	if node.Parent().Type() == "array_declarator" && node.Parent().Parent().ChildByFieldName("type") != nil {
		typeNode := node.Parent().Parent().ChildByFieldName("type")
		varType = typeNode.Content(sourceCode) + "[]"
	}
	if node.Parent().Type() == "array_declarator" && node.Parent().Parent().Type() == "pointer_declarator" && node.Parent().Parent().Parent().ChildByFieldName("type") != nil {
		typeNode := node.Parent().Parent().Parent().ChildByFieldName("type")
		varType = typeNode.Content(sourceCode) + "[]"
	}
	if varType == "" {
		return "", errors.New("definition type not found for node")
	}
	return varType, nil
}

// Returns true if the idenitifer node provided is a parameter declaration, i.e.
// is part of a parameter list. For example, for the source code
// "Integer AddOne(Integer num) { Integer augend = 1; return num + augend; }",
// where the idenitifer node is the node which represents "num", returns true and
// the idenitifer node which represents "augend" returns false.
func isParamDeclaration(node *sitter.Node) bool {
	isPointerArrayParam := node.Parent().Type() == "array_declarator" && node.Parent().Parent().Type() == "pointer_declarator" && node.Parent().Parent().Parent().Type() == "parameter_declaration"
	isArrayParam := node.Parent().Parent().Type() == "parameter_declaration" && node.Parent().Type() == "array_declarator"
	isPointerDeclaratorChild := node.Parent().Type() == "pointer_declarator"
	isParameterDeclarationChild := node.Parent().Type() == "parameter_declaration"
	return isPointerDeclaratorChild || isParameterDeclarationChild || isArrayParam || isPointerArrayParam
}

// Create the hover documentation docstring from the provided variable type,
// identifier, description and prefix. The prefix will be surrounded by "()" if
// it is provided, otherwise it will be omitted.
func createHoverDeclarationDocString(varType, identifier, desc, prefix string) string {
	if prefix != "" {
		return protocol.CreateDocMarkdownString(fmt.Sprintf("(%s) %s %s", prefix, varType, identifier), desc)
	}
	return protocol.CreateDocMarkdownString(fmt.Sprintf("%s %s", varType, identifier), desc)
}

// Filters the library items so that it matches argument list described by the
// function that the identifier node is referring to.
func filterLibItems(identifierNode *sitter.Node, libItems []string, uri string, documents map[string]Document, includesDir string) []string {
	doc, ok := documents[uri]
	if !ok {
		return []string{}
	}
	sourceCode := doc.SourceCode

	getArgumentTypes := func(argsNode *sitter.Node) []string {
		var types []string
		for i := 0; i < int(argsNode.ChildCount()); i++ {
			argIdentifierNode := argsNode.Child(i)
			if argIdentifierNode == nil {
				continue
			}
			switch argIdentifierNode.Type() {
			case "identifier":
				def, err := findDefinition(argIdentifierNode, argIdentifierNode.Content(sourceCode), uri, documents, includesDir)
				if err != nil {
					continue
				}
				nodeType, err := getDefinitionType(def.Node, sourceCode)
				if err != nil {
					continue
				}
				types = append(types, nodeType)

			case "string_literal":
				types = append(types, "Text")

			case "number_literal":
				types = append(types, "Integer")

			case "subscript_expression":
				subscriptArgumentIdentifierNode := argIdentifierNode.ChildByFieldName("argument")
				if subscriptArgumentIdentifierNode == nil {
					break
				}
				def, err := findDefinition(subscriptArgumentIdentifierNode, subscriptArgumentIdentifierNode.Content(sourceCode), uri, documents, includesDir)
				if err != nil {
					break
				}
				varType, err := getDefinitionType(def.Node, sourceCode)
				if err != nil {
					break
				}
				// The argument identifier node is a subscript expression node,
				// which means we want the type base type and not the array
				// type.
				varType = strings.TrimSuffix(varType, "[]")
				types = append(types, varType)

			case "binary_expression":
				expressionNode := argIdentifierNode
				// Binary expressions are recursive, we need to traverse down
				// to the leaf of the binary expression tree.
				for expressionNode.ChildByFieldName("left") != nil {
					expressionNode = expressionNode.ChildByFieldName("left")
				}
				switch expressionNode.Type() {
				case "identifier":
					def, err := findDefinition(expressionNode, expressionNode.Content(sourceCode), uri, documents, includesDir)
					if err != nil {
						break
					}
					varType, err := getDefinitionType(def.Node, sourceCode)
					if err != nil {
						break
					}
					types = append(types, varType)

				case "number_literal":
					types = append(types, "Integer")

				case "string_literal":
					types = append(types, "Text")
				}

			case "call_expression":
				funcIdentifierNode := argIdentifierNode.ChildByFieldName("function")
				if funcIdentifierNode == nil {
					break
				}
				if def, err := findDefinition(funcIdentifierNode, funcIdentifierNode.Content(sourceCode), uri, documents, includesDir); err == nil {
					varType, err := getDefinitionType(def.Node, sourceCode)
					if err != nil {
						break
					}
					types = append(types, varType)
					break
				}
				libItems, ok := lang.Lib[funcIdentifierNode.Content(sourceCode)]
				if !ok || len(libItems) == 0 {
					break
				}
				returnType, err := lang.GetReturnType(libItems[0])
				if err != nil {
					break
				}
				types = append(types, returnType)
			}
		}
		return types
	}

	var result []string
	callExpressionNode := identifierNode.Parent()
	argsNode := callExpressionNode.ChildByFieldName("arguments")
	if argsNode == nil {
		return []string{}
	}
	funcIdentifier := identifierNode.Content(sourceCode)
	types := getArgumentTypes(argsNode)
	signaturePattern := ""
	// This matches "Type (&?)Identifier".
	// basePattern := `%s\s*&?\w+`
	isArrayType := func(t string) bool {
		return strings.HasSuffix(t, "[]")
	}
	for idx, t := range types {
		if alias, ok := lang.TypeAliases[t]; ok {
			for _, a := range alias {
				t = fmt.Sprintf("%s|%s", t, a)
			}
			t = fmt.Sprintf("(?:%s)", t)
		}
		if idx == 0 {
			if isArrayType(t) {
				signaturePattern = fmt.Sprintf(`%s\s*&?\w+\[\]`, strings.TrimSuffix(t, "[]"))
				continue
			}
			signaturePattern = fmt.Sprintf(`%s\s*&?\w+`, t)
			continue
		}

		if isArrayType(t) {
			signaturePattern = fmt.Sprintf(`%s,\s*%s\s*&?\w+\[\]`, signaturePattern, strings.TrimSuffix(t, "[]"))
			continue
		} else {
			signaturePattern = fmt.Sprintf(`%s,\s*%s\s*&?\w+`, signaturePattern, t)
		}
	}
	codeBlockStartPattern := `12dpl\n\w+\s*`
	codeBlockEndPattern := `\n` + "\\`\\`\\`"
	// This creates the pattern:
	// ```12dpl\\n\w+\s*
	// |             |identifier
	// |             |      |
	// |             |      |signature pattern
	// |             |      |       |
	// |             |      |       | \\n```
	// |             |      |       ||     |
	// ```12dpl\nvoid Print(Text msg)\n```\n---\nPrint the Text msg to the Output Window.
	//
	// This is a bit of a hack to make sure we are matching the signature and
	// not anything in the description, as there are some lib items which
	// reference other library items by function signature. We should really
	// restructure the library item struct so that it has a description,
	// signature and doc field.
	signaturePattern = fmt.Sprintf(`%s%s\(%s\)%s`, codeBlockStartPattern, funcIdentifier, signaturePattern, codeBlockEndPattern)
	for _, item := range libItems {
		if matched, _ := regexp.MatchString(signaturePattern, item); matched {
			result = append(result, item)
		}
		continue
	}
	return result
}

type Document struct {
	// Root of the parsed nodes for the document.
	RootNode *sitter.Node
	// Document source code.
	SourceCode []byte
}

type DefinitionResult struct {
	Range parser.Range
	Node  *sitter.Node
	URI   string
}

// Find the definition of the node reprepsented by start node and identifier.
// The start node is the identifier node representing the identifier.
func findDefinition(startNode *sitter.Node, identifier string, uri string, documents map[string]Document, includesDir string) (DefinitionResult, error) {
	doc, ok := documents[uri]
	if !ok {
		return DefinitionResult{}, errors.New("document not found")
	}

	sourceCode := doc.SourceCode
	if startNode.Parent() != nil && startNode.Parent().Type() == "call_expression" {
		locRange, node, err := parser.FindFuncDefinition(identifier, sourceCode)
		return DefinitionResult{Range: locRange, Node: node, URI: uri}, err
	}

	// No point looking at nodes past the identifier node.
	isNodeRowAfterIdentifierNode := func(node *sitter.Node) bool {
		return node.StartPoint().Row > startNode.EndPoint().Row
	}
	currentNode := startNode
	for currentNode != nil {
		if currentNode.Type() == "function_definition" {
			funcDefIdentifierNode := getFuncDefIdentifierNode(currentNode)
			if funcDefIdentifierNode != nil && funcDefIdentifierNode.Content(sourceCode) == identifier {
				return DefinitionResult{Range: parser.NewParserRange(funcDefIdentifierNode), Node: funcDefIdentifierNode, URI: uri}, nil
			}
			paramsNode := getFuncDefParamsNode(currentNode)
			if paramNode, err := getParamNode(paramsNode, identifier, sourceCode); err == nil {
				return DefinitionResult{Range: parser.NewParserRange(paramNode), Node: paramNode, URI: uri}, nil
			}
		}

		for i := 0; i < int(currentNode.ChildCount()); i++ {
			currentChildNode := currentNode.Child(i)
			if currentChildNode.Type() == "preproc_def" {
				identifierDeclarationNode := currentChildNode.ChildByFieldName("name")
				if identifierDeclarationNode != nil && identifierDeclarationNode.Content(sourceCode) == identifier {
					return DefinitionResult{Range: parser.NewParserRange(identifierDeclarationNode), Node: identifierDeclarationNode, URI: uri}, nil
				}
			}
			if currentChildNode.Type() == "preproc_include" {
				if pathNode := currentChildNode.ChildByFieldName("path"); pathNode != nil {
					includeFilepath := getIncludeFilepath(pathNode, sourceCode, includesDir)
					includeURI := protocol.URI(includeFilepath)
					if includeDoc, ok := documents[includeURI]; ok {
						includeRootNode := includeDoc.RootNode
						// TODO: we should keep track of the includes we have
						// already visited and put a limit on the number of
						// recursions we can allow. Otherwise we will blow the
						// stack if the user has authored an import cycle.
						if def, err := findDefinition(includeRootNode, identifier, includeURI, documents, includesDir); err == nil {
							return def, nil
						}
					}
				}
			}
			if currentChildNode.Type() == "compound_statement" {
				for i := 0; i < int(currentChildNode.ChildCount()); i++ {
					if isNodeRowAfterIdentifierNode(currentChildNode.Child(i)) {
						break
					}
					locRange, n, err := findDeclaration(currentChildNode.Child(i), identifier, sourceCode)
					if err != nil {
						continue
					}
					return DefinitionResult{Range: locRange, Node: n, URI: uri}, nil
				}
			}
			// No point looking at nodes past the identifier node.
			if isNodeRowAfterIdentifierNode(currentChildNode) {
				break
			}
			locRange, n, err := findDeclaration(currentChildNode, identifier, sourceCode)
			if err != nil {
				continue
			}
			return DefinitionResult{Range: locRange, Node: n, URI: uri}, nil
		}
		currentNode = currentNode.Parent()
	}
	return DefinitionResult{}, errors.New("parent function definition not found")
}

// Get the full filepath of the include file described by path node.
func getIncludeFilepath(pathNode *sitter.Node, sourceCode []byte, includesDir string) string {
	pathQuoted := pathNode.Content(sourceCode)
	pathUnquoted := pathQuoted[1 : len(pathQuoted)-1]
	includeFilepath := filepath.Join(includesDir, pathUnquoted)
	return includeFilepath
}

// Get the identifier node of the provided function definition node.
func getFuncDefIdentifierNode(node *sitter.Node) *sitter.Node {
	return node.ChildByFieldName("declarator").ChildByFieldName("declarator")
}

// Get the function definition parameters node.
func getFuncDefParamsNode(node *sitter.Node) *sitter.Node {
	return node.ChildByFieldName("declarator").ChildByFieldName("parameters")
}

// Find the parameter node with the provided identifier name in the parameters
// node. Returns an error if the node with the identifier cannot be found.
func getParamNode(paramsNode *sitter.Node, identifier string, sourceCode []byte) (*sitter.Node, error) {
	for i := 0; i < int(paramsNode.ChildCount()); i++ {
		paramNode := paramsNode.Child(i)
		paramDeclaratorNode := paramNode.ChildByFieldName("declarator")
		if paramDeclaratorNode == nil {
			continue
		}
		if paramDeclaratorNode.Type() == "pointer_declarator" {
			identifierNode := paramDeclaratorNode.ChildByFieldName("declarator")
			if identifierNode.Type() == "array_declarator" {
				identifierNode = identifierNode.ChildByFieldName("identifier")
			}
			if identifierNode != nil {
				if identifierNode.Content(sourceCode) == identifier {
					return identifierNode, nil
				}
			}
		}
		if paramDeclaratorNode.Type() == "array_declarator" {
			if identifierNode := paramDeclaratorNode.ChildByFieldName("identifier"); identifierNode != nil {
				if identifierNode.Content(sourceCode) == identifier {
					return identifierNode, nil
				}
			}
		}
		if paramDeclaratorNode.Type() == "identifier" &&
			paramDeclaratorNode.Content(sourceCode) == identifier {
			return paramDeclaratorNode, nil
		}
	}
	return nil, errors.New("parameter node not found")
}

// Finds the declaration of the identifier inside of the declaration node and
// returns the range. If the declaration node of the identifier cannot be found,
// an error will be returned. For example, for a declaration node representing
// "Integer a = 1, b;":
//
// (declaration
//
//	type: (primitive_type)
//	declarator: (init_declarator
//	  declarator: (identifier)
//	  value: (number_literal))
//	declarator: (identifier))
//
// If the identifier is of value "a" the range is ([0, 8] - [0, 9]), if "b",
// ([0, 15] - [0, 16]).
func findDeclaration(node *sitter.Node, identifier string, sourceCode []byte) (parser.Range, *sitter.Node, error) {
	if node.Type() != "declaration" {
		return parser.Range{}, nil, errors.New("node is not a declaration node")
	}
	declaratorNode := node.ChildByFieldName("declarator")
	for declaratorNode != nil {
		switch declaratorNode.Type() {
		// Uninitialized variable declaration.
		case "identifier":
			identifierDeclarationNode := declaratorNode
			if identifierDeclarationNode.Content(sourceCode) == identifier {
				return parser.NewParserRange(identifierDeclarationNode), identifierDeclarationNode, nil
			}

		// Initialized variable declaration.
		case "init_declarator":
			identifierDeclarationNode := declaratorNode.ChildByFieldName("declarator")
			if identifierDeclarationNode == nil {
				break
			}
			if identifierDeclarationNode.Content(sourceCode) == identifier {
				return parser.NewParserRange(identifierDeclarationNode), identifierDeclarationNode, nil
			}

		case "array_declarator":
			identifierDeclarationNode := declaratorNode.ChildByFieldName("identifier")
			if identifierDeclarationNode == nil {
				break
			}
			if identifierDeclarationNode.Content(sourceCode) == identifier {
				return parser.NewParserRange(identifierDeclarationNode), identifierDeclarationNode, nil
			}
		}

		declaratorNode = declaratorNode.NextNamedSibling()
	}
	return parser.Range{}, nil, errors.New("declaration not found")
}

// Converts parser range into protocol range.
func ToProtocolRange(r parser.Range) protocol.Range {
	result := protocol.Range{
		Start: protocol.Position{
			Line:      uint(r.Start.Row),
			Character: uint(r.Start.Column),
		},
		End: protocol.Position{
			Line:      uint(r.End.Row),
			Character: uint(r.End.Column),
		},
	}
	return result
}

// Formats content into LSP format by adding in headers and field names ready
// to send over the wire.
func ToProtocolMessage(contentBytes []byte) string {
	return fmt.Sprintf("%s: %d\r\n\r\n%s", contentLengthHeaderName, len(contentBytes), contentBytes)
}

func stringifyRequestMessage(msg protocol.RequestMessage) string {
	return fmt.Sprintf("    id: %d\n    method: %s\n    params: %s", msg.ID, msg.Method, string(msg.Params))
}

func newServerCapabilities() protocol.ServerCapabilities {
	// Disabling resolve provider so that it simplifies our implementation by
	// not having to calculate the documentation in a separate goroutine and
	// resolving at a later time. We should enable this if we find generating
	// completion items are expensive. We set this flag so that we can provide
	// at least one filed to the completion options so that our server responds
	// to the client that we provide completion services.
	resolveProvider := false
	definitionProvider := true
	textDocumentSyncKind := protocol.TextDocumentSyncKindFull
	documentFormattingProvider := true
	result := protocol.ServerCapabilities{
		CompletionProvider: &protocol.CompletionOptions{
			ResolveProvider: &resolveProvider,
		},
		DefinitionProvider:         &definitionProvider,
		DocumentFormattingProvider: &documentFormattingProvider,
		HoverProvider:              true,
		ReferencesProvider:         true,
		RenameProvider:             true,
		TextDocumentSync:           &textDocumentSyncKind,
	}
	return result
}

func newNullResponseMessage(id int64) protocol.ResponseMessage {
	return protocol.ResponseMessage{
		ID:     id,
		Result: json.RawMessage(protocol.NullResult),
	}
}

func isSupportedIndentationNodeType(nodeType string) bool {
	for _, supportedType := range supportedIndentationNodeTypes {
		if nodeType == supportedType {
			return true
		}
	}
	return false
}
