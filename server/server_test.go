package server_test

import (
	"bufio"
	"encoding/json"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
	"testing"

	"go.uber.org/goleak"

	"github.com/kelly-lin/12d-lang-server/protocol"
	"github.com/kelly-lin/12d-lang-server/server"
	"github.com/stretchr/testify/assert"
)

func TestServer(t *testing.T) {
	mustNewLocationResponseMessage := func(start, end protocol.Position) protocol.ResponseMessage {
		msg, err := newLocationResponseMessage(1, "file:///foo.4dm", start, end)
		assert.NoError(t, err)
		return msg
	}

	t.Run("textDocument/definition", func(t *testing.T) {
		// Helper returns the response message and fails if the test if the
		// response message could not be created.
		type TestCase struct {
			Desc       string
			SourceCode string
			Pos        protocol.Position
			Want       protocol.ResponseMessage
		}
		testCases := []TestCase{
			{
				Desc: "func identifier",
				SourceCode: `Integer Add(Integer augend, Integer addend) {
    return augend + addend;
}

void main() {
    Integer result = Add(1, 2);
}`,
				Pos: protocol.Position{Line: 5, Character: 21},
				Want: mustNewLocationResponseMessage(
					protocol.Position{Line: 0, Character: 8},
					protocol.Position{Line: 0, Character: 11},
				),
			},
			{
				Desc: "func parameter identifier",
				SourceCode: `Integer Add(Integer augend, Integer addend) {
    return augend + addend;
}`,
				Pos: protocol.Position{Line: 1, Character: 11},
				Want: mustNewLocationResponseMessage(
					protocol.Position{Line: 0, Character: 20},
					protocol.Position{Line: 0, Character: 26},
				),
			},
			{
				Desc: "func parameter identifier in multiline parameter list",
				SourceCode: `Integer Add(
    Integer augend,
    Integer addend
) {
    return augend + addend;
}`,
				Pos: protocol.Position{Line: 4, Character: 11},
				Want: mustNewLocationResponseMessage(
					protocol.Position{Line: 1, Character: 12},
					protocol.Position{Line: 1, Character: 18},
				),
			},
			{
				Desc: "binary expression local variable",
				SourceCode: `Integer Add_one(Integer addend) {
    Integer augend = 1;
    return augend + addend;
}`,
				Pos: protocol.Position{Line: 2, Character: 11},
				Want: mustNewLocationResponseMessage(
					protocol.Position{Line: 1, Character: 12},
					protocol.Position{Line: 1, Character: 18},
				),
			},
			{
				Desc: "local variable",
				SourceCode: `Integer One() {
    Integer result = 1;
    return result;
}`,
				Pos: protocol.Position{Line: 2, Character: 11},
				Want: mustNewLocationResponseMessage(
					protocol.Position{Line: 1, Character: 12},
					protocol.Position{Line: 1, Character: 18},
				),
			},
			{
				Desc: "local variable inside for loop",
				SourceCode: `Integer Looper() {
    for (Integer i = 1; i <= 10; i++) {
        Integer j = i;
    }
}`,
				Pos: protocol.Position{Line: 2, Character: 20},
				Want: mustNewLocationResponseMessage(
					protocol.Position{Line: 1, Character: 17},
					protocol.Position{Line: 1, Character: 18},
				),
			},
			{
				Desc: "local variable outside for loop",
				SourceCode: `Integer Looper() {
    Integer k = 1;
    for (Integer i = 1; i <= 10; i++) {
        Integer j = k;
    }
}`,
				Pos: protocol.Position{Line: 3, Character: 20},
				Want: mustNewLocationResponseMessage(
					protocol.Position{Line: 1, Character: 12},
					protocol.Position{Line: 1, Character: 13},
				),
			},
			{
				Desc: "local variable inside for loop",
				SourceCode: `Integer Looper() {
    for (Integer i = 1; i <= 10; i++) {
        Integer k = 1;
        Integer j = k;
    }
}`,
				Pos: protocol.Position{Line: 3, Character: 20},
				Want: mustNewLocationResponseMessage(
					protocol.Position{Line: 2, Character: 16},
					protocol.Position{Line: 2, Character: 17},
				),
			},
			{
				Desc: "declaration without initialisation",
				SourceCode: `void Validate_source_box(Source_Box source_box) {
    Dynamic_Element elts;
    Validate(source_box, elts);
}`,
				Pos: protocol.Position{Line: 2, Character: 25},
				Want: mustNewLocationResponseMessage(
					protocol.Position{Line: 1, Character: 20},
					protocol.Position{Line: 1, Character: 24},
				),
			},
			{
				Desc: "preproc definition",
				SourceCode: `#define DEBUG 1

void main() {
    if (DEBUG) {
        Print("debug");
    }
}`,
				Pos: protocol.Position{Line: 3, Character: 8},
				Want: mustNewLocationResponseMessage(
					protocol.Position{Line: 0, Character: 8},
					protocol.Position{Line: 0, Character: 13},
				),
			},
			{
				Desc: "global scope",
				SourceCode: `{
    Integer AREA_CODE = 10;
}

void main() {
    Integer result = AREA_CODE + 1;
}`,
				Pos: protocol.Position{Line: 5, Character: 21},
				Want: mustNewLocationResponseMessage(
					protocol.Position{Line: 1, Character: 12},
					protocol.Position{Line: 1, Character: 21},
				),
			},
		}
		for _, testCase := range testCases {
			t.Run(testCase.Desc, func(t *testing.T) {
				defer goleak.VerifyNone(t)
				assert := assert.New(t)
				logger, err := newLogger()
				assert.NoError(err)
				in, out, cleanUp := startServer(logger)
				defer cleanUp()

				var id int64 = 1
				didOpenMsgBytes, err := newDidOpenRequestMessageBytes(id, "file:///foo.4dm", testCase.SourceCode)
				assert.NoError(err)
				_, err = in.Writer.Write([]byte(server.ToProtocolMessage(didOpenMsgBytes)))
				assert.NoError(err)

				definitionMsgBytes, err := newDefinitionRequestMessageBytes(id, "file:///foo.4dm", testCase.Pos)
				assert.NoError(err)
				_, err = in.Writer.Write([]byte(server.ToProtocolMessage(definitionMsgBytes)))
				assert.NoError(err)

				got, err := getReponseMessage(out.Reader)
				assert.NoError(err)
				assert.Equal(testCase.Want.ID, got.ID)
				assert.Equal(testCase.Want.Error, got.Error)
				assert.Equal(string(testCase.Want.Result), string(got.Result))
			})
		}
	})

	// This is essentially a go to definition test but the source gets updated]
	// after the initial did open request.
	t.Run("textDocument/didChange", func(t *testing.T) {
		defer goleak.VerifyNone(t)
		assert := assert.New(t)
		logger, err := newLogger()
		assert.NoError(err)
		in, out, cleanUp := startServer(logger)
		defer cleanUp()

		sourceCodeOnOpen := `void main() {
    Add(1, 1);
}`
		var openRequestID int64 = 1
		didOpenMsgBytes, err := newDidOpenRequestMessageBytes(openRequestID, "file:///foo.4dm", sourceCodeOnOpen)
		assert.NoError(err)
		_, err = in.Writer.Write([]byte(server.ToProtocolMessage(didOpenMsgBytes)))
		assert.NoError(err)

		pos1 := protocol.Position{Line: 1, Character: 4}
		var defintionRequestID1 int64 = 2
		definitionMsg1Bytes, err := newDefinitionRequestMessageBytes(defintionRequestID1, "file:///foo.4dm", pos1)
		assert.NoError(err)
		_, err = in.Writer.Write([]byte(server.ToProtocolMessage(definitionMsg1Bytes)))
		assert.NoError(err)

		// We should receive a no definition result here since the did open
		// request source code does not yet have the function defined.
		got, err := getReponseMessage(out.Reader)
		assert.NoError(err)
		wantOnOpen := protocol.ResponseMessage{ID: defintionRequestID1, Result: []byte("null"), Error: nil}
		assert.Equal(wantOnOpen.ID, got.ID)
		assert.Equal(wantOnOpen.Error, got.Error)
		assert.Equal(string(wantOnOpen.Result), string(got.Result))

		// Source code got updated.
		sourceCodeOnChange := `Integer Add(Integer addend, Integer augend) {
    return addend, augend;
}

void main() {
    Add(1, 1);
}`
		var onChangeID int64 = 3
		didChangeMsgBytes, err := newDidChangeRequestMessageBytes(onChangeID, "file:///foo.4dm", sourceCodeOnChange)
		assert.NoError(err)
		_, err = in.Writer.Write([]byte(server.ToProtocolMessage(didChangeMsgBytes)))
		assert.NoError(err)

		var definitionRequestID2 int64 = 1
		pos2 := protocol.Position{Line: 5, Character: 4}
		definitionMsg2Bytes, err := newDefinitionRequestMessageBytes(definitionRequestID2, "file:///foo.4dm", pos2)
		assert.NoError(err)
		_, err = in.Writer.Write([]byte(server.ToProtocolMessage(definitionMsg2Bytes)))
		assert.NoError(err)

		// The new source code now has the definition for the function.
		got, err = getReponseMessage(out.Reader)
		assert.NoError(err)
		want := mustNewLocationResponseMessage(
			protocol.Position{Line: 0, Character: 8},
			protocol.Position{Line: 0, Character: 11},
		)
		assert.Equal(want.ID, got.ID)
		assert.Equal(want.Error, got.Error)
		assert.Equal(string(want.Result), string(got.Result))
	})
}

// Creates a new protocol request message with definition params and returns the
// wire representation.
func newDefinitionRequestMessageBytes(id int64, uri string, position protocol.Position) ([]byte, error) {
	definitionParams := protocol.DefinitionParams{
		TextDocumentPositionParams: protocol.TextDocumentPositionParams{
			TextDocument: protocol.TextDocumentIdentifier{
				URI: uri,
			},
			Position: position,
		},
	}
	definitionParamsBytes, err := json.Marshal(definitionParams)
	if err != nil {
		return nil, err
	}
	definitionMsg := protocol.RequestMessage{
		JSONRPC: "2.0",
		ID:      id,
		Method:  "textDocument/definition",
		Params:  json.RawMessage(definitionParamsBytes),
	}
	definitionMsgBytes, err := json.Marshal(definitionMsg)
	if err != nil {
		return nil, err
	}
	return definitionMsgBytes, nil
}

func newDidOpenRequestMessageBytes(id int64, uri, text string) ([]byte, error) {
	didOpenParams := protocol.DidOpenTextDocumentParams{
		TextDocument: protocol.TextDocumentItem{
			URI:        uri,
			LanguageID: "12dpl",
			Text:       text,
		},
	}
	didOpenParamsBytes, err := json.Marshal(didOpenParams)
	if err != nil {
		return nil, err
	}
	didOpenMsg := protocol.RequestMessage{
		JSONRPC: "2.0",
		ID:      id,
		Method:  "textDocument/didOpen",
		Params:  json.RawMessage(didOpenParamsBytes),
	}
	didOpenMsgBytes, err := json.Marshal(didOpenMsg)
	if err != nil {
		return nil, err
	}
	return didOpenMsgBytes, nil
}

func newDidChangeRequestMessageBytes(id int64, uri, text string) ([]byte, error) {
	didChangeParams := protocol.DidChangeTextDocumentParams{
		TextDocument: protocol.VersionedTextDocumentIdentifier{
			Version: 1,
			TextDocumentIdentifier: protocol.TextDocumentIdentifier{
				URI: uri,
			},
		},
		ContentChanges: []protocol.TextDocumentContentChangeEvent{
			{
				Text: text,
			},
		},
	}
	didChangeParamsBytes, err := json.Marshal(didChangeParams)
	if err != nil {
		return nil, err
	}
	didChangeMsg := protocol.RequestMessage{
		JSONRPC: "2.0",
		ID:      id,
		Method:  "textDocument/didChange",
		Params:  json.RawMessage(didChangeParamsBytes),
	}
	didChangeMsgBytes, err := json.Marshal(didChangeMsg)
	if err != nil {
		return nil, err
	}
	return didChangeMsgBytes, nil
}

// Creates a new protocol response message with definition location and returns
// the wire representation.
func newLocationResponseMessage(id int64, uri string, start, end protocol.Position) (protocol.ResponseMessage, error) {
	locationBytes, err := json.Marshal(protocol.Location{
		URI:   uri,
		Range: protocol.Range{Start: start, End: end},
	})
	if err != nil {
		return protocol.ResponseMessage{}, err
	}
	msg := protocol.ResponseMessage{ID: id, Result: json.RawMessage(locationBytes)}
	return msg, nil
}

// Creates a new logging function for debugging.
func newLogger() (func(msg string), error) {
	file, err := os.Create("/tmp/server_test.txt")
	if err != nil {
		return nil, err
	}
	logger := func(msg string) {
		_, _ = file.WriteString(msg)
	}
	return logger, nil
}

// Starts the language server in a goroutine and returns the input pipe, output
// pipe and a clean up function.
func startServer(logger func(msg string)) (Pipe, Pipe, func()) {
	serv := server.NewServer(logger)
	inReader, inWriter := io.Pipe()
	outReader, outWriter := io.Pipe()
	go (func() {
		if err := serv.Serve(inReader, outWriter); err != nil {
			logger(fmt.Sprintf("%s\n", err))
			return
		}
	})()
	cleanUp := func() {
		inReader.Close()
		inWriter.Close()
		outReader.Close()
		outWriter.Close()
	}
	return Pipe{Reader: inReader, Writer: inWriter},
		Pipe{Reader: outReader, Writer: outWriter},
		cleanUp
}

type Pipe struct {
	Reader *io.PipeReader
	Writer *io.PipeWriter
}

// Reads a single message from reader returns the parsed response message.
func getReponseMessage(rd io.Reader) (protocol.ResponseMessage, error) {
	r := bufio.NewReader(rd)
	line, err := r.ReadString('\n')
	if err != nil {
		return protocol.ResponseMessage{}, err
	}
	numBytesString := strings.TrimPrefix(line, "Content-Length: ")
	numBytes, err := strconv.Atoi(strings.TrimSpace(numBytesString))
	if err != nil {
		return protocol.ResponseMessage{}, err
	}
	_, err = r.ReadString('\n')
	if err != nil {
		return protocol.ResponseMessage{}, err
	}
	msgBytes := make([]byte, numBytes)
	_, _ = io.ReadFull(r, msgBytes)
	if err != nil {
		return protocol.ResponseMessage{}, err
	}
	var msg protocol.ResponseMessage
	if err := json.Unmarshal(msgBytes, &msg); err != nil {
		return protocol.ResponseMessage{}, err
	}
	return msg, nil
}
