package main

import (
	"bufio"
	"encoding/json"
	"errors"
	"flag"
	"fmt"
	"io"
	"os"
	"regexp"
	"strconv"
	"strings"
)

const logFilepath = "/tmp/12d-lang-server.log"
const contentLengthHeaderName = "Content-Length"

var ErrUnhandledMethod = errors.New("unhandled method")

var debugFlag = flag.Bool("d", false, "enable debugging features")
var helpFlag = flag.Bool("h", false, "show help")

func main() {
	flag.Parse()
	flag.CommandLine.SetOutput(os.Stdout)
	flag.Usage = printUsage
	if *helpFlag {
		flag.Usage()
		os.Exit(0)
	}

	log, cleanUp, err := setupLogging(*debugFlag)
	if err != nil {
		log("failed to setup logging")
	}
	defer cleanUp()

	reader := bufio.NewReader(os.Stdin)
	for {
		log("\n\nreading message...\n")
		msg, err := ReadMessage(reader)
		if err != nil {
			log(err.Error())
		}
		log(fmt.Sprintf("method: %s\n", msg.Method))
		log(fmt.Sprintf("message id: %d\n", msg.ID))
		params, err := msg.Params.MarshalJSON()
		if err != nil {
			log(fmt.Sprintf("could not unmarshal params: %s\n", err))
		}
		log(fmt.Sprintf("params: %s\n", params))

		// Notifications do not reply to the client.
		if IsNotification(msg.Method) {
			log("is notification, skipping...")
			continue
		}

		content, err := HandleMessage(msg)
		if err != nil {
			log(fmt.Sprintf("could not handle message %v: %s\n", msg, err))
			continue
		}
		contentBytes, err := json.Marshal(content)
		if err != nil {
			log("could not marshal contents")
			continue
		}
		res := ToProtocol(contentBytes)
		log(fmt.Sprintf("response: \n%s", res))
		if _, err = fmt.Fprint(os.Stdout, res); err != nil {
			log(fmt.Sprintf("could print message to output %v: %s\n", msg, err))
			continue
		}
	}
}

// TODO: Hand rolling this for now, ideally we should use cobra-cli.
func printUsage() {
	fmt.Printf(`Language server for the 12d programming language

Usage: 12d-auth-server [-dh]

Flags:
`)
	flag.PrintDefaults()
}

// Since stdio is used for IPC, we need to log to a file instead of stdout.
func setupLogging(debugModeEnabled bool) (func(msg string), func(), error) {
	log := func(msg string) {}
	cleanUp := func() {}
	if debugModeEnabled {
		_ = os.Remove(logFilepath)
		file, err := os.OpenFile(logFilepath, os.O_CREATE|os.O_WRONLY, 0666)
		if err != nil {
			fmt.Printf("could not open file: %s\n", err)
			return func(msg string) {}, func() {}, err
		}
		log = func(msg string) {
			_, _ = file.Write([]byte(msg))
		}
		cleanUp = func() { file.Close() }
	}
	return log, cleanUp, nil
}

func ReadMessage(r *bufio.Reader) (RequestMessage, error) {
	message := RequestMessage{}
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

type RequestMessage struct {
	JSONRPC string          `json:"jsonrpc"`
	ID      int64           `json:"id"`
	Method  string          `json:"method"`
	Params  json.RawMessage `json:"params"`
}

type ResponseMessage struct {
	ID     int64            `json:"id"`
	Result *json.RawMessage `json:"result,omitempty"`
	Error  *ResponseError   `json:"error,omitempty"`
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
	Label string `json:"label"`
	Kind  *uint  `json:"kind,omitempty"`
	Data  any    `json:"data,omitempty"`
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

// Handles the request message and returns the response.
func HandleMessage(msg RequestMessage) (ResponseMessage, error) {
	// Not going to handle any LSP version specific methods for now.
	if matched, _ := regexp.MatchString(`^\$\/.+`, msg.Method); matched {
		err := ResponseError{Code: -32601, Message: "unhandled method"}
		return ResponseMessage{ID: msg.ID, Error: &err}, nil
	}

	switch msg.Method {
	case "initialize":
		resolveProvider := true
		result := InitializeResult{
			Capabilities: ServerCapabilities{
				CompletionProvider: &CompletionOptions{
					ResolveProvider: &resolveProvider,
				},
			},
		}
		resultBytes, err := json.Marshal(result)
		if err != nil {
			return ResponseMessage{}, err
		}
		return ResponseMessage{
			ID:     msg.ID,
			Result: (*json.RawMessage)(&resultBytes),
		}, nil

	case "textDocument/completion":
		items := []CompletionItem{{Label: "Typescript"}, {Label: "Javascript"}}
		resultBytes, err := json.Marshal(items)
		if err != nil {
			return ResponseMessage{}, err
		}
		return ResponseMessage{
			ID:     msg.ID,
			Result: (*json.RawMessage)(&resultBytes),
		}, nil

	default:
		// Unhandled method.
		return ResponseMessage{}, ErrUnhandledMethod
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
