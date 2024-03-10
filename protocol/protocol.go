package protocol

import (
	"encoding/json"
	"fmt"
	"strings"
)

const (
	CompletionItemKindText          = "text"
	CompletionItemKindMethod        = "method"
	CompletionItemKindFunction      = "function"
	CompletionItemKindConstructor   = "constructor"
	CompletionItemKindField         = "field"
	CompletionItemKindVariable      = "variable"
	CompletionItemKindClass         = "class"
	CompletionItemKindInterface     = "interface"
	CompletionItemKindModule        = "module"
	CompletionItemKindProperty      = "property"
	CompletionItemKindUnit          = "unit"
	CompletionItemKindValue         = "value"
	CompletionItemKindEnum          = "enum"
	CompletionItemKindKeyword       = "keyword"
	CompletionItemKindSnippet       = "snippet"
	CompletionItemKindColor         = "color"
	CompletionItemKindFile          = "file"
	CompletionItemKindReference     = "reference"
	CompletionItemKindFolder        = "folder"
	CompletionItemKindEnumMember    = "enummember"
	CompletionItemKindConstant      = "constant"
	CompletionItemKindStruct        = "struct"
	CompletionItemKindEvent         = "event"
	CompletionItemKindOperator      = "operator"
	CompletionItemKindTypeParameter = "typeparameter"
)

const (
	TextDocumentSyncKindNone        uint = 0
	TextDocumentSyncKindFull        uint = 1
	TextDocumentSyncKindIncremental uint = 2
)

const (
	CompletionTriggerKindInvoked                         int = 1
	CompletionTriggerKindTriggerCharacter                int = 2
	CompletionTriggerKindTriggerForIncompleteCompletions int = 3
)

const (
	MarkupKindPlainText string = "plaintext"
	MarkupKindMarkdown  string = "markdown"
)

var NullResult = json.RawMessage("null")

// Converts filepath into a URI.
func URI(filepath string) string {
	scheme := "file"
	path := filepath
	path = strings.ReplaceAll(path, "\\", "/")
	if len(path) > 0 && path[0] != '/' {
		path = "/" + path
	}
	return fmt.Sprintf("%s://%s", scheme, path)
}

func GetCompletionItemKind(kind string) *uint {
	var result uint
	switch kind {
	case "text":
		result = 1
	case "method":
		result = 2
	case "function":
		result = 3
	case "constructor":
		result = 4
	case "field":
		result = 5
	case "variable":
		result = 6
	case "class":
		result = 7
	case "interface":
		result = 8
	case "module":
		result = 9
	case "property":
		result = 10
	case "unit":
		result = 11
	case "value":
		result = 12
	case "enum":
		result = 13
	case "keyword":
		result = 14
	case "snippet":
		result = 15
	case "color":
		result = 16
	case "file":
		result = 17
	case "reference":
		result = 18
	case "folder":
		result = 19
	case "enummember":
		result = 20
	case "constant":
		result = 21
	case "struct":
		result = 22
	case "event":
		result = 23
	case "operator":
		result = 24
	case "typeparameter":
		result = 25
	default:
		result = 1
	}
	return &result
}

type RequestMessage struct {
	JSONRPC string          `json:"jsonrpc"`
	ID      int64           `json:"id"`
	Method  string          `json:"method"`
	Params  json.RawMessage `json:"params"`
}

type ResponseMessage struct {
	ID     int64           `json:"id"`
	Result json.RawMessage `json:"result,omitempty"`
	Error  *ResponseError  `json:"error,omitempty"`
}

type ResponseError struct {
	Code    int    `json:"code"`
	Message string `json:"message"`
	Data    any    `json:"data,omitempty"`
}

type InitializeResult struct {
	Capabilities ServerCapabilities `json:"capabilities"`
	ServerInfo   *ServerInfo        `json:"serverInfo,omitempty"`
}

type CompletionResult struct {
	IsIncomplete bool             `json:"isIncomplete"`
	Items        []CompletionItem `json:"items"`
}

type CompletionItem struct {
	Label         string         `json:"label"`
	Kind          *uint          `json:"kind,omitempty"`
	Data          any            `json:"data,omitempty"`
	Documentation *MarkupContent `json:"documentation,omitempty"`
	Detail        string         `json:"detail,omitempty"`
}

type MarkupContent struct {
	Kind  string `json:"kind"`
	Value string `json:"value"`
}

type ServerCapabilities struct {
	CompletionProvider         *CompletionOptions `json:"completionProvider,omitempty"`
	DefinitionProvider         *bool              `json:"definitionProvider,omitempty"`
	DocumentFormattingProvider *bool              `json:"documentFormattingProvider,omitempty"`
	HoverProvider              bool               `json:"hoverProvider"`
	ReferencesProvider         bool               `json:"referencesProvider"`
	TextDocumentSync           *uint              `json:"textDocumentSync,omitempty"`
}

type CompletionOptions struct {
	ResolveProvider *bool `json:"resolveProvider,omitempty"`
}

type ServerInfo struct {
	Name    string  `json:"name"`
	Version *string `json:"version"`
}

type DidOpenTextDocumentParams struct {
	TextDocument TextDocumentItem `json:"textDocument"`
}

type TextDocumentItem struct {
	URI        string `json:"uri"`
	LanguageID string `json:"languageId"`
	Version    int    `json:"version"`
	Text       string `json:"text"`
}

type DefinitionParams struct {
	TextDocumentPositionParams
}

type TextDocumentPositionParams struct {
	TextDocument TextDocumentIdentifier `json:"textDocument"`
	Position     Position               `json:"position"`
}

type TextDocumentIdentifier struct {
	URI string `json:"uri"`
}

type Position struct {
	Line      uint `json:"line"`
	Character uint `json:"character"`
}

type HoverParams struct {
	TextDocumentPositionParams
}

type Hover struct {
	Contents []string `json:"contents"`
}

type MarkedString struct {
	Language string `json:"language"`
	Value    string `json:"value"`
}

type Location struct {
	URI   string `json:"uri"`
	Range Range  `json:"range"`
}

type Range struct {
	Start Position `json:"start"`
	End   Position `json:"end"`
}

type DidChangeTextDocumentParams struct {
	TextDocument   VersionedTextDocumentIdentifier  `json:"textDocument"`
	ContentChanges []TextDocumentContentChangeEvent `json:"contentChanges"`
}

type VersionedTextDocumentIdentifier struct {
	Version int `json:"version"`
	TextDocumentIdentifier
}

type TextDocumentContentChangeEvent struct {
	Text string `json:"text"`
}

type CompletionParams struct {
	TextDocumentPositionParams
	Context CompletionContext `json:"context,omitempty"`
}

type CompletionContext struct {
	TriggerKind      int    `json:"triggerKind"`
	TriggerCharacter string `json:"triggerCharacter,omitempty"`
}

type DocumentFormattingParams struct {
	TextDocument TextDocumentIdentifier `json:"textDocument"`
	Options      FormattingOptions      `json:"options"`
}

type FormattingOptions struct {
	// Size of a tab in spaces.
	TabSize uint `json:"tabSize"`
	// Prefer spaces over tabs.
	InsertSpaces bool `json:"insertSpaces"`
	// Trim trailing whitespace on a line.
	TrimTrailingWhitespace *bool `json:"trimTrailingWhitespace,omitempty"`
	// Insert a newline character at the end of the file if one does not exist.
	InsertFinalNewline *bool `json:"insertFinalNewline,omitempty"`
	// Trim all newlines after the final newline at the end of the file.
	TrimFinalNewlines *bool `json:"trimFinalNewlines,omitempty"`
}

type TextEdit struct {
	Range   Range  `json:"range"`
	NewText string `json:"newText"`
}

type ReferenceParams struct {
	TextDocumentPositionParams
	Context ReferenceContext `json:"context"`
}

type ReferenceContext struct {
	// Include the declaration of the current symbol.
	IncludeDeclaration bool `json:"includeDeclaration"`
}
