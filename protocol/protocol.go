package protocol

import "encoding/json"

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
	Label         string        `json:"label"`
	Kind          *uint         `json:"kind,omitempty"`
	Data          any           `json:"data,omitempty"`
	Documentation MarkUpContent `json:"documentation,omitempty"`
}

type MarkUpContent struct {
	Kind  string `json:"kind"`
	Value string `json:"value"`
}

type ServerCapabilities struct {
	CompletionProvider *CompletionOptions `json:"completionProvider,omitempty"`
	DefinitionProvider *bool              `json:"definitionProvider,omitempty"`
}

type CompletionOptions struct {
	ResolveProvider *bool `json:"resolveProvider,omitempty"`
}

type ServerInfo struct {
	Name    string  `json:"name"`
	Version *string `json:"version"`
}
