package main

import (
	"flag"
	"fmt"
	"os"

	"github.com/kelly-lin/12d-lang-server/server"
)

const logFilepath = "/tmp/12d-lang-server.log"

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

	langServer := server.NewServer(log)
	langServer.Serve(os.Stdin, os.Stdout)
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
