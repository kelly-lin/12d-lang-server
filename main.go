package main

import (
	"bufio"
	"encoding/json"
	"flag"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

const logFilepath = "/tmp/12d-lang-server.log"

var debugFlag = flag.Bool("d", false, "enable debugging features")
var helpFlag = flag.Bool("h", false, "show help")

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

type RequestMessage struct {
	Jsonrpc string          `json:"jsonrpc"`
	ID      int64           `json:"id"`
	Method  string          `json:"method"`
	Params  json.RawMessage `json:"params"`
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

// TODO: Hand rolling this for now, ideally we should use cobra-cli.
func printUsage() {
	fmt.Printf(`Language server for the 12d programming language

Usage: 12d-auth-server [-dh]

Flags:
`)
	flag.PrintDefaults()
}

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
		msg, err := ReadMessage(reader)
		if err != nil {
			log(err.Error())
		}
		log(fmt.Sprintf("method: %s\n", msg.Method))
		log(fmt.Sprintf("message id: %d\n", msg.ID))
	}
}
