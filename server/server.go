package server

import (
	"bufio"
	"encoding/json"
	"errors"
	"fmt"
	"io"
	"os"
	"regexp"
	"strconv"
	"strings"

	"github.com/kelly-lin/12d-lang-server/protocol"
)

const contentLengthHeaderName = "Content-Length"

var ErrUnhandledMethod = errors.New("unhandled method")

// Serve reads JSONRPC from the reader, processes the message and responds by
// writing to writer.
func Serve(rd io.Reader, w io.Writer, logger func(msg string)) {
    reader := bufio.NewReader(rd)
	for {
		logger("\n------------------------------------------------------------------\nreading message...\n")
		msg, err := ReadMessage(reader)
		if err != nil {
			logger(err.Error())
		}
		logMsg(logger, msg)

		if msg.Method == "exit" {
			os.Exit(0)
		}

		// Notifications do not reply to the client.
		if IsNotification(msg.Method) {
			logger("is notification, skipping...")
			continue
		}

		content, err := HandleMessage(msg)
		if err != nil {
			logger(fmt.Sprintf("could not handle message %v: %s\n", msg, err))
			continue
		}
		contentBytes, err := json.Marshal(content)
		if err != nil {
			logger("could not marshal contents")
			continue
		}
		res := ToProtocol(contentBytes)
		logger(fmt.Sprintf("response: \n%s", res))
		if _, err = fmt.Fprint(os.Stdout, res); err != nil {
			logger(fmt.Sprintf("could print message to output %v: %s\n", msg, err))
			continue
		}
	}
}

func ReadMessage(r *bufio.Reader) (protocol.RequestMessage, error) {
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
			contentLength, err = strconv.ParseInt(value, 10, 64)
			if err != nil {
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

// Handles the request message and returns the response.
func HandleMessage(msg protocol.RequestMessage) (protocol.ResponseMessage, error) {
	// Not going to handle any LSP version specific methods for now.
	if matched, _ := regexp.MatchString(`^\$\/.+`, msg.Method); matched {
		err := protocol.ResponseError{Code: -32601, Message: "unhandled method"}
		return protocol.ResponseMessage{ID: msg.ID, Error: &err}, nil
	}

	doc := protocol.MarkUpContent{Kind: "markdown", Value: "`Integer Get_command_argument(Integer i, Text &argument, Integer i, Text &argument, Integer i, Text &argument)`" + "\n\nGet the number of tokens in the program command-line. The number of tokens is returned as the function return value. For some example code, see 5. 4 Command Line-Arguments."}

	switch msg.Method {
	case "initialize":
		resolveProvider := true
		result := protocol.InitializeResult{
			Capabilities: protocol.ServerCapabilities{
				CompletionProvider: &protocol.CompletionOptions{
					ResolveProvider: &resolveProvider,
				},
			},
		}
		resultBytes, err := json.Marshal(result)
		if err != nil {
			return protocol.ResponseMessage{}, err
		}
		return protocol.ResponseMessage{
			ID:     msg.ID,
			Result: json.RawMessage(resultBytes),
		}, nil

	case "textDocument/completion":
		items := []protocol.CompletionItem{
			{Label: "Typescript", Documentation: doc},
			{Label: "Javascript", Documentation: doc},
			{Label: "Boo", Documentation: doc},
		}
		resultBytes, err := json.Marshal(items)
		if err != nil {
			return protocol.ResponseMessage{}, err
		}
		return protocol.ResponseMessage{
			ID:     msg.ID,
			Result: json.RawMessage(resultBytes),
		}, nil

	case "completionItem/resolve":
		item := protocol.CompletionItem{
			Label:         "Typescript",
			Documentation: doc}
		resultBytes, err := json.Marshal(item)
		if err != nil {
			return protocol.ResponseMessage{}, err
		}
		return protocol.ResponseMessage{
			ID:     msg.ID,
			Result: json.RawMessage(resultBytes),
		}, nil

	case "shutdown":
		return protocol.ResponseMessage{
			ID:     msg.ID,
			Result: []byte("null"),
		}, nil

	default:
		// Unhandled method.
		return protocol.ResponseMessage{}, ErrUnhandledMethod
	}
}

func ToProtocol(contentBytes []byte) string {
	return fmt.Sprintf("%s: %d\r\n\r\n%s", contentLengthHeaderName, len(contentBytes), contentBytes)
}

func IsNotification(method string) bool {
	switch method {
	case "initialized":
		return true

	default:
		return false
	}
}

func logMsg(log func(msg string), msg protocol.RequestMessage) {
	log(fmt.Sprintf("method: %s\n", msg.Method))
	log(fmt.Sprintf("message id: %d\n", msg.ID))
	params, err := msg.Params.MarshalJSON()
	if err != nil {
		log(fmt.Sprintf("could not unmarshal params: %s\n", err))
	}
	log(fmt.Sprintf("params: %s\n", params))
}
