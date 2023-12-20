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
		defer goleak.VerifyNone(t)
		assert := assert.New(t)
		file, err := os.Create("/tmp/server_test.txt")
		assert.NoError(err)
		logger := func(msg string) {
			_, _ = file.WriteString(msg)
		}
		serv := server.NewServer(logger)
		inReader, inWriter := io.Pipe()
		defer inReader.Close()
		defer inWriter.Close()
		outReader, outWriter := io.Pipe()
		defer outReader.Close()
		defer outWriter.Close()
		go (func(inReader *io.PipeReader, outWriter *io.PipeWriter) {
			if err := serv.Serve(inReader, outWriter); err != nil {
				logger(fmt.Sprintf("%s\n", err))
				return
			}
		})(inReader, outWriter)

		didOpenMsg := protocol.RequestMessage{
			JSONRPC: "2.0",
			ID:      1,
			Method:  "textDocument/didOpen",
		}
		didOpenParams := protocol.DidOpenTextDocumentParams{
			TextDocument: protocol.TextDocumentItem{
				URI:        "file:///foo.4dm",
				LanguageID: "12dpl",
				Text:       "void main() {}",
			},
		}
		didOpenParamsBytes, err := json.Marshal(didOpenParams)
		assert.NoError(err)
		didOpenMsg.Params = json.RawMessage(didOpenParamsBytes)
		didOpenMsgBytes, err := json.Marshal(didOpenMsg)
		assert.NoError(err)
		_, err = inWriter.Write([]byte(server.ToProtocolMessage(didOpenMsgBytes)))
		assert.NoError(err)

		definitionMsg := protocol.RequestMessage{
			JSONRPC: "2.0",
			ID:      1,
			Method:  "textDocument/definition",
		}
		definitionParams := protocol.DefinitionParams{
			TextDocumentPositionParams: protocol.TextDocumentPositionParams{
				TextDocument: protocol.TextDocumentIdentifier{
					URI: "file:///foo.4dm",
				},
				Position: protocol.Position{
					Line:      0,
					Character: 5,
				},
			},
		}
		definitionParamsBytes, err := json.Marshal(definitionParams)
		assert.NoError(err)
		definitionMsg.Params = json.RawMessage(definitionParamsBytes)
		definitionMsgBytes, err := json.Marshal(definitionMsg)
		assert.NoError(err)
		_, err = inWriter.Write([]byte(server.ToProtocolMessage(definitionMsgBytes)))
		assert.NoError(err)

		r := bufio.NewReader(outReader)
		line, err := r.ReadString('\n')
		assert.NoError(err)
		numBytesString := strings.TrimPrefix(line, "Content-Length: ")
		numBytes, err := strconv.Atoi(strings.TrimSpace(numBytesString))
		assert.NoError(err)
		_, err = r.ReadString('\n')
		assert.NoError(err)

		got := make([]byte, numBytes)
		_, _ = io.ReadFull(r, got)
		assert.NoError(err)

		locationBytes, err := json.Marshal(protocol.Location{
			URI: "file:///foo.4dm",
			Range: protocol.Range{
				Start: protocol.Position{
					Line:      0,
					Character: 5,
				},
				End: protocol.Position{
					Line:      0,
					Character: 9,
				},
			},
		})
		assert.NoError(err)
		wantMsg := protocol.ResponseMessage{ID: 1, Result: json.RawMessage(locationBytes)}
		want, err := json.Marshal(wantMsg)
		assert.NoError(err)
		assert.Equal(want, got)
	})
}
