// Generates and prints to standard output, the go code for API documentation
// through the provided manual file generated by the documentation generation
// tool.
package main

import (
	"encoding/json"
	"fmt"
	"io"
	"os"
	"regexp"
	"text/template"
)

func main() {
	if len(os.Args) < 2 {
		fmt.Fprintln(os.Stderr, "please provide the path to API documentation json as the first argument")
		os.Exit(1)
	}
	manualFilepath := os.Args[1]
	if _, err := os.Stat(manualFilepath); err != nil {
		fmt.Fprintf(os.Stderr, "manual filepath provided at %s does not exist\n", manualFilepath)
		os.Exit(1)
	}

	file, err := os.Open(manualFilepath)
	if err != nil {
		fmt.Printf("could not open manual file at %s: %s\n", manualFilepath, err)
		os.Exit(1)
	}
	defer file.Close()
	contentBytes, err := io.ReadAll(file)
	if err != nil {
		fmt.Printf("could not read json file contents: %s\n", err)
		os.Exit(1)
	}
	var manual Manual
	if err := json.Unmarshal(contentBytes, &manual); err != nil {
		fmt.Printf("error unmarshalling json contents: %s\n", err)
		os.Exit(1)
	}

	agg := map[string][]string{}
	for _, api := range manual.Items {
		for _, name := range api.Names {
			re := regexp.MustCompile(`\w+ (\w+)\(`)
			matches := re.FindStringSubmatch(name)
			if len(matches) > 1 {
				funcName := matches[1]
				agg[funcName] = append(agg[funcName], createDocMarkdownString(name, api.Desc))
			}
		}
	}
	templ := template.Must(template.New("sourceCode").Parse(`// AUTOGENERATED FILE DO NOT MODIFY
package lang

type ManualItem struct {
	Desc string
}

var Lib = map[string][]ManualItem{
{{range $name, $descriptions := .}}    "{{$name}}": {
{{- range $description := $descriptions}}
        {Desc: "{{$description}}"},
{{- end}}
    },
{{end}}}
`))
	if err := templ.Execute(os.Stdout, agg); err != nil {
		fmt.Printf("could not execute template: %s\n", err)
		os.Exit(1)
	}
}

type Manual struct {
	Items []ManualItem `json:"items"`
}

type ManualItem struct {
	Names []string `json:"names"`
	Desc  string   `json:"description"`
	ID    string   `json:"id"`
}

// Creates the documentation markdown string from the provided signature as
// 12dpl code and description as markdown.
func createDocMarkdownString(signature, desc string) string {
	if signature == "" {
		return desc
	}
	if desc == "" {
		return fmt.Sprintf("```12dpl\\n%s\\n```", signature)
	}
	// If we use description directly we will be using the unescaped version
	// we read in from the JSON file. This is problematic because we are
	// generating code which requires the escaped version and causes issues when
	// we are creating generated code with unescaped characters, such as quotes.
	// We are marshalling description again to get the escaped version.
	encodedDesc, _ := json.Marshal(desc)
	return fmt.Sprintf("```12dpl\\n%s\\n```\\n---\\n%s", signature, encodedDesc[1:len(encodedDesc)-1])
}
