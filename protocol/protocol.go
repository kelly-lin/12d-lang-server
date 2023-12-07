package protocol

import "encoding/json"

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
}

type CompletionOptions struct {
	ResolveProvider *bool `json:"resolveProvider,omitempty"`
}

type ServerInfo struct {
	Name    string  `json:"name"`
	Version *string `json:"version"`
}
