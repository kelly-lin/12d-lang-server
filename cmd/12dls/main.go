package main

import (
	"flag"
	"fmt"
	"os"
	"path/filepath"

	"github.com/kelly-lin/12d-lang-server/server"
)

// Set by linker flag.
var version string

var logFileFlag = flag.String("l", "", "server logs to file, useful for debugging")
var includesDirFlag = flag.String("i", "", "includes directory")
var helpFlag = flag.Bool("h", false, "show help")
var versionFlag = flag.Bool("v", false, "show version")

func main() {
	flag.Parse()
	flag.CommandLine.SetOutput(os.Stdout)
	flag.Usage = printUsage
	if *helpFlag {
		flag.Usage()
		os.Exit(0)
	}
	if *versionFlag {
		fmt.Println(version)
		os.Exit(0)
	}

	log, cleanUp, err := setupLogging(*logFileFlag)
	if err != nil {
		log("failed to setup logging")
	}
	defer cleanUp()

	includesDir, err := filepath.Abs(*includesDirFlag)
	if err != nil {
		log(fmt.Sprintf("failed to get absolute path to includes directory: %s\n", err.Error()))
		os.Exit(1)
	}
	langServer := server.NewServer(includesDir, &server.BuiltInLangCompletions, server.NewFSResolver(includesDir), log)
	if err := langServer.Serve(os.Stdin, os.Stdout); err != nil {
		log(fmt.Sprintf("%s\n", err.Error()))
		os.Exit(1)
	}
}

// TODO: Hand rolling this for now, ideally we should use cobra-cli.
func printUsage() {
	fmt.Printf(`Language server for the 12d programming language

Usage: 12dls [-i includes_dir][-l log_filepath][-hv]

Flags:
`)
	flag.PrintDefaults()
}

// Since stdio is used for IPC, we need to log to a file instead of stdout.
func setupLogging(logFilepath string) (func(msg string), func(), error) {
	log := func(msg string) {}
	cleanUp := func() {}
	if logFilepath != "" {
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
