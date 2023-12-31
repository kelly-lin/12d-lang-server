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
	t.Run("textDocument/definition", func(t *testing.T) {
		t.Run("func identifier", func(t *testing.T) {
			defer goleak.VerifyNone(t)
			assert := assert.New(t)
			logger, err := newLogger()
			assert.NoError(err)
			in, out, cleanUp := startServer(logger)
			defer cleanUp()

			var id int64 = 1
			uri := "file:///foo.4dm"
			text := `Integer Add(Integer augend, Integer addend) {
    return augend + addend;
}

void main() {
    Integer result = Add(1, 2);
}`
			didOpenMsgBytes, err := newDidOpenRequestMessageBytes(id, uri, text)
			assert.NoError(err)
			_, err = in.Writer.Write([]byte(server.ToProtocolMessage(didOpenMsgBytes)))
			assert.NoError(err)

			position := protocol.Position{Line: 5, Character: 21}
			definitionMsgBytes, err := newDefinitionRequestMessageBytes(id, uri, position)
			assert.NoError(err)
			_, err = in.Writer.Write([]byte(server.ToProtocolMessage(definitionMsgBytes)))
			assert.NoError(err)

			got, err := getReponseMessage(out.Reader)
			assert.NoError(err)
			want, err := newLocationResponseMessage(
				id,
				uri,
				protocol.Position{Line: 0, Character: 8},
				protocol.Position{Line: 0, Character: 11},
			)
			assert.NoError(err)
			assert.Equal(want, got)
		})
	})

	t.Run("func parameter identifier", func(t *testing.T) {
		defer goleak.VerifyNone(t)
		assert := assert.New(t)
		logger, err := newLogger()
		assert.NoError(err)
		in, out, cleanUp := startServer(logger)
		defer cleanUp()

		var id int64 = 1
		uri := "file:///foo.4dm"
		text := `Integer Add(Integer augend, Integer addend) {
    return augend + addend;
}

void main() {
    Integer result = Add(1, 2);
}`
		didOpenMsgBytes, err := newDidOpenRequestMessageBytes(id, uri, text)
		assert.NoError(err)
		_, err = in.Writer.Write([]byte(server.ToProtocolMessage(didOpenMsgBytes)))
		assert.NoError(err)

		// This is refers to the augend variable in the return statement.
		position := protocol.Position{Line: 1, Character: 11}
		definitionMsgBytes, err := newDefinitionRequestMessageBytes(id, uri, position)
		assert.NoError(err)
		_, err = in.Writer.Write([]byte(server.ToProtocolMessage(definitionMsgBytes)))
		assert.NoError(err)

		got, err := getReponseMessage(out.Reader)
		assert.NoError(err)
		want, err := newLocationResponseMessage(
			id,
			uri,
			// This is refers to the augend parameter.
			protocol.Position{Line: 0, Character: 20},
			protocol.Position{Line: 0, Character: 26},
		)
		assert.NoError(err)
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
