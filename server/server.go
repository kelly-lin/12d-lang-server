package server

import (
	"bufio"
	"context"
	"encoding/json"
	"errors"
	"fmt"
	"io"
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

// Creates a new language server. The logger function parameter specifies the
// function to call for logging. If the logger is nil, will default to a
// function that does not log anything.
func NewServer(logger func(msg string)) Server {
	serverLogger := func(msg string) {}
	if logger != nil {
		serverLogger = logger
	}

	return Server{
		documents: make(map[string][]byte),
		logger:    serverLogger,
		nodes:     make(map[string]*sitter.Node),
	}
}

// Language server.
type Server struct {
	// Map of file URI and parsed nodes
	nodes map[string]*sitter.Node
	// Map of file URI and source code.
	// TODO: should we be storing a []byte instead of a string? If most of our
	// consumers are expecting []byte, we should change this type.
	documents map[string][]byte
	logger    func(msg string)
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
		s.logger(fmt.Sprintf("response: \n%s", resMsg))
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

	// TODO: stub documentation markdown, to extract this out to a formatting
	// function.
	doc := protocol.MarkUpContent{Kind: "markdown", Value: "`Integer Get_command_argument(Integer i, Text &argument, Integer i, Text &argument, Integer i, Text &argument)`" + "\n\nGet the number of tokens in the program command-line. The number of tokens is returned as the function return value. For some example code, see 5. 4 Command Line-Arguments."}

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
		// TODO: Below are stub completion items, to replace with proper
		// completion items.
		items := []protocol.CompletionItem{
			{Label: "Typescript", Documentation: doc},
			{Label: "Javascript", Documentation: doc},
			{Label: "Boo", Documentation: doc},
		}
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

	case "completionItem/resolve":
		item := protocol.CompletionItem{
			Label:         "Typescript",
			Documentation: doc}
		resultBytes, err := json.Marshal(item)
		if err != nil {
			return protocol.ResponseMessage{}, 0, err
		}
		return protocol.ResponseMessage{
				ID:     msg.ID,
				Result: json.RawMessage(resultBytes),
			},
			0,
			nil

	case "textDocument/hover":
		var params protocol.HoverParams
		if err := json.Unmarshal(msg.Params, &params); err != nil {
			return newNullResponseMessage(msg.ID), len(protocol.NullResult), err
		}
		rootNode, ok := s.nodes[params.TextDocument.URI]
		if !ok {
			return newNullResponseMessage(msg.ID), len(protocol.NullResult), errors.New("source node not found")
		}
		sourceCode, ok := s.documents[params.TextDocument.URI]
		if !ok {
			return newNullResponseMessage(msg.ID), len(protocol.NullResult), errors.New("source code not found")
		}
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
		var contents []string
		if identifierNode.Parent().Type() == "call_expression" {
			_, node, err := findDefinition(identifierNode, identifier, sourceCode)
			if err != nil {
				// We cannot find the definition, try find it in the library
				// items.
				libItems, ok := lang.Lib[identifier]
				if !ok || len(libItems) == 0 {
					return newNullResponseMessage(msg.ID), len(protocol.NullResult), nil
				}
				contents = filterLibItems(identifierNode, libItems, sourceCode)
			} else {
				// We found the definition, get the signature.
				// TODO: this might cause us issues as we are assuming the
				// structure of the tree. Might need to refactor this so that we
				// search for the ancestor "function_definition" node.
				funcDefNode := node.Parent().Parent()
				if funcDefNode != nil {
					typeNode := funcDefNode.ChildByFieldName("type")
					declaratorNode := funcDefNode.ChildByFieldName("declarator")
					docNode := funcDefNode.PrevSibling()
					desc := ""
					if docNode != nil && docNode.Type() == "comment" {
						desc = docNode.Content(sourceCode)
						desc = formatDescComment(desc)
					}
					if typeNode != nil && declaratorNode != nil {
						declaration := declaratorNode.Content(sourceCode)
						declaration = formatFuncDeclaration(declaration)
						contents = append(contents, createHoverDeclarationDocString(typeNode.Content(sourceCode), declaration, desc, ""))
					}
				}
			}
		} else {
			if _, node, err := findDefinition(identifierNode, identifier, sourceCode); err == nil && node.Type() == "identifier" {
				if nodeType, err := getDefinitionType(node, sourceCode); err == nil {
					prefix := ""
					identifier := node.Content(sourceCode)
					if isParameterDeclaration(node) {
						prefix = "parameter"
						if node.Parent().Type() == "pointer_declarator" {
							identifier = node.Parent().Content(sourceCode)
						}
					}
					if node.Parent().Type() == "function_declarator" {
						funcDefNode := node.Parent().Parent()
						if funcDefNode != nil {
							typeNode := funcDefNode.ChildByFieldName("type")
							declaratorNode := funcDefNode.ChildByFieldName("declarator")
							docNode := funcDefNode.PrevSibling()
							desc := ""
							if docNode != nil && docNode.Type() == "comment" {
								desc = docNode.Content(sourceCode)
								desc = formatDescComment(desc)
							}
							if typeNode != nil && declaratorNode != nil {
								declaration := declaratorNode.Content(sourceCode)
								declaration = formatFuncDeclaration(declaration)
								contents = append(contents, createHoverDeclarationDocString(typeNode.Content(sourceCode), declaration, desc, ""))
							}
						}
					} else {
						contents = append(contents, createHoverDeclarationDocString(nodeType, identifier, "", prefix))
					}
				}
			}
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
		if err := s.updateDocument(params.TextDocument.URI, params.TextDocument.Text); err != nil {
			return protocol.ResponseMessage{}, 0, err
		}
		return protocol.ResponseMessage{}, 0, nil

	case "textDocument/didChange":
		var params protocol.DidChangeTextDocumentParams
		if err := json.Unmarshal(msg.Params, &params); err != nil {
			return protocol.ResponseMessage{}, 0, err
		}
		// The server currently only supports a full document sync.
		if err := s.updateDocument(params.TextDocument.URI, params.ContentChanges[len(params.ContentChanges)-1].Text); err != nil {
			return protocol.ResponseMessage{}, 0, err
		}
		return protocol.ResponseMessage{}, 0, nil

	case "textDocument/definition":
		var params protocol.DefinitionParams
		if err := json.Unmarshal(msg.Params, &params); err != nil {
			return protocol.ResponseMessage{}, 0, err
		}
		rootNode, ok := s.nodes[params.TextDocument.URI]
		if !ok {
			return protocol.ResponseMessage{}, 0, errors.New("source node not found")
		}
		sourceCode, ok := s.documents[params.TextDocument.URI]
		if !ok {
			return protocol.ResponseMessage{}, 0, errors.New("source code not found")
		}
		identifierNode, err := parser.FindIdentifierNode(rootNode, params.Position.Line, params.Position.Character)
		if errors.Is(err, parser.ErrNoDefinition) {
			return newNullResponseMessage(msg.ID),
				len(protocol.NullResult),
				nil
		}
		if err != nil {
			return newNullResponseMessage(msg.ID),
				len(protocol.NullResult),
				err
		}
		identifier := identifierNode.Content(sourceCode)
		locRange, _, err := findDefinition(identifierNode, identifier, sourceCode)
		if err != nil {
			return newNullResponseMessage(msg.ID),
				len(protocol.NullResult),
				nil
		}
		location := protocol.Location{
			URI:   params.TextDocument.URI,
			Range: ToProtocolRange(locRange),
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

	case "initialized":
		return protocol.ResponseMessage{}, 0, nil

	default:
		return protocol.ResponseMessage{}, 0, ErrUnhandledMethod
	}
}

// Update the document stored on the server identified by the uri with provided
// content.
func (s *Server) updateDocument(uri string, content string) error {
	s.documents[uri] = []byte(content)
	rootNode, err := sitter.ParseCtx(context.Background(), []byte(content), parser.GetLanguage())
	if err != nil {
		return err
	}
	s.nodes[uri] = rootNode
	return nil
}

// Formats the function declaration for display as documentation.
func formatFuncDeclaration(declaration string) string {
	declarationLines := strings.Split(declaration, "\n")
	var newDeclarationLines []string
	for _, line := range declarationLines {
		newLine := strings.TrimSpace(line)
		newDeclarationLines = append(newDeclarationLines, newLine)
	}
	result := strings.Join(newDeclarationLines, "")
	result = strings.ReplaceAll(result, ",", ", ")
	return result
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

// Gets the definition type of the provided identifier node. For example, a node
// which represents: "Integer One = 1;" where node has content "One", will
// return "Integer".
func getDefinitionType(node *sitter.Node, sourceCode []byte) (string, error) {
	var typeNode *sitter.Node
	if node.Parent().Type() == "preproc_def" && node.Parent().ChildByFieldName("value").Child(0) != nil {
		if node.Parent().ChildByFieldName("value").Child(0).Type() == "string_literal" {
			return "Text", nil
		}
		if node.Parent().ChildByFieldName("value").Child(0).Type() == "number_literal" {
			return "Integer", nil
		}
	}
	if node.Parent().Type() == "declaration" && node.Parent().ChildByFieldName("type") != nil {
		typeNode = node.Parent().ChildByFieldName("type")
	}
	if node.Parent().Type() == "init_declarator" && node.Parent().Parent().ChildByFieldName("type") != nil {
		typeNode = node.Parent().Parent().ChildByFieldName("type")
	}
	if node.Parent().Type() == "parameter_declaration" {
		typeNode = node.Parent().ChildByFieldName("type")
	}
	if node.Parent().Type() == "pointer_declarator" && node.Parent().Parent().ChildByFieldName("type") != nil {
		typeNode = node.Parent().Parent().ChildByFieldName("type")
	}
	if node.Parent().Type() == "function_declarator" && node.Parent().Parent().ChildByFieldName("type") != nil {
		typeNode = node.Parent().Parent().ChildByFieldName("type")
	}
	if typeNode == nil {
		return "", errors.New("definition type not found for node")
	}
	return typeNode.Content(sourceCode), nil
}

// Returns true if the idenitifer node provided is a parameter declaration, i.e.
// is part of a parameter list. For example, for the source code
// "Integer AddOne(Integer num) { Integer augend = 1; return num + augend; }",
// where the idenitifer node is the node which represents "num", returns true and
// the idenitifer node which represents "augend" returns false.
func isParameterDeclaration(node *sitter.Node) bool {
	return node.Parent().Type() == "pointer_declarator" || node.Parent().Type() == "parameter_declaration"
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
func filterLibItems(identifierNode *sitter.Node, libItems []string, sourceCode []byte) []string {
	getArgumentTypes := func(argsNode *sitter.Node) []string {
		var types []string
		for i := 0; i < int(argsNode.ChildCount()); i++ {
			argIdentifierNode := argsNode.Child(i)
			if argIdentifierNode == nil {
				continue
			}
			switch argIdentifierNode.Type() {
			case "identifier":
				_, node, err := findDefinition(argIdentifierNode, argIdentifierNode.Content(sourceCode), sourceCode)
				if err != nil {
					continue
				}
				nodeType, err := getDefinitionType(node, sourceCode)
				if err != nil {
					continue
				}
				types = append(types, nodeType)

			case "string_literal":
				types = append(types, "Text")

			case "number_literal":
				types = append(types, "Integer")
			}
		}
		return types
	}

	var result []string
	argsNode := identifierNode.Parent().ChildByFieldName("arguments")
	if argsNode == nil {
		return []string{}
	}
	funcIdentifier := identifierNode.Content(sourceCode)
	types := getArgumentTypes(argsNode)
	pattern := ""
	for idx, t := range types {
		if idx == 0 {
			pattern = fmt.Sprintf(`%s\s*&?\w+`, t)
			continue
		}
		pattern = fmt.Sprintf(`%s,\s*%s\s*&?\w+`, pattern, t)
	}
	pattern = fmt.Sprintf(`%s\(%s\)`, funcIdentifier, pattern)
	for _, item := range libItems {
		if matched, _ := regexp.MatchString(pattern, item); matched {
			result = append(result, item)
		}
		continue
	}
	return result
}

// Find the definition of the node reprepsenting by identifier node and
// identifier. The identifier node is the target for the definition.
func findDefinition(identifierNode *sitter.Node, identifier string, sourceCode []byte) (parser.Range, *sitter.Node, error) {
	switch identifierNode.Parent().Type() {
	case "call_expression":
		// Is this byte slice conversion expensive? If it is, we might need to
		// find a way so that we do not have to do the conversion. Ideally we
		// should just need to parse the source code once and cache it.
		locRange, node, err := parser.FindFuncDefinition(identifier, sourceCode)
		return locRange, node, err

	default:
		currentNode := identifierNode
		for currentNode.Parent() != nil {
			currentNode = currentNode.Parent()
			if currentNode.Type() == "function_definition" {
				funcIdentifierMode := currentNode.ChildByFieldName("declarator").ChildByFieldName("declarator")
				if funcIdentifierMode != nil && funcIdentifierMode.Content(sourceCode) == identifier {
					return parser.NewParserRange(funcIdentifierMode), funcIdentifierMode, nil
				}
				paramsNode := currentNode.ChildByFieldName("declarator").ChildByFieldName("parameters")
				if paramNode, err := findParameterNode(paramsNode, identifier, sourceCode); err == nil {
					return parser.NewParserRange(paramNode), paramNode, nil
				}
			}
			for i := 0; i < int(currentNode.ChildCount()); i++ {
				currentChildNode := currentNode.Child(i)
				if currentChildNode.Type() == "preproc_def" {
					identifierDeclarationNode := currentChildNode.ChildByFieldName("name")
					if identifierDeclarationNode != nil && identifierDeclarationNode.Content(sourceCode) == identifier {
						return parser.NewParserRange(identifierDeclarationNode), identifierDeclarationNode, nil
					}
				}
				if currentChildNode.Type() == "compound_statement" {
					for i := 0; i < int(currentChildNode.ChildCount()); i++ {
						locRange, n, err := findDeclaration(currentChildNode.Child(i), identifier, sourceCode)
						if err != nil {
							continue
						}
						return locRange, n, nil
					}
				}
				locRange, n, err := findDeclaration(currentChildNode, identifier, sourceCode)
				if err != nil {
					continue
				}
				return locRange, n, nil
			}
		}
		return parser.Range{}, nil, errors.New("parent function definition not found")
	}
}

// Find the parameter node with the provided identifier name in the parameters
// node. Returns an error if the node with the identifier cannot be found.
func findParameterNode(paramsNode *sitter.Node, identifier string, sourceCode []byte) (*sitter.Node, error) {
	for i := 0; i < int(paramsNode.ChildCount()); i++ {
		paramNode := paramsNode.Child(i)
		paramDeclaratorNode := paramNode.ChildByFieldName("declarator")
		if paramDeclaratorNode == nil {
			continue
		}
		if paramDeclaratorNode.Type() == "pointer_declarator" {
			identifierNode := paramDeclaratorNode.ChildByFieldName("declarator")
			if identifierNode != nil {
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
				continue
			}
			if identifierDeclarationNode.Content(sourceCode) == identifier {
				return parser.NewParserRange(identifierDeclarationNode), identifierDeclarationNode, nil
			}

		default:
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
	resolveProvider := true
	definitionProvider := true
	textDocumentSyncKind := protocol.TextDocumentSyncKindFull
	result := protocol.ServerCapabilities{
		CompletionProvider: &protocol.CompletionOptions{
			ResolveProvider: &resolveProvider,
		},
		DefinitionProvider: &definitionProvider,
		HoverProvider:      true,
		TextDocumentSync:   &textDocumentSyncKind,
	}
	return result
}

func newNullResponseMessage(id int64) protocol.ResponseMessage {
	return protocol.ResponseMessage{
		ID:     id,
		Result: json.RawMessage(protocol.NullResult),
	}
}
