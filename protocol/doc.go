package protocol

import (
	"encoding/json"
	"fmt"
)

// Creates the documentation markdown string from the provided signature as
// 12dpl code and description as markdown.
func CreateDocMarkdownString(signature, desc string) string {
	if signature == "" {
		return desc
	}
	if desc == "" {
		return fmt.Sprintf("```12dpl\n%s\n```", signature)
	}
	// If we use description directly we will be using the unescaped version
	// we read in from the JSON file. This is problematic because we are
	// generating code which requires the escaped version and causes issues when
	// we are creating generated code with unescaped characters, such as quotes.
	// We are marshalling description again to get the escaped version.
	encodedDesc, _ := json.Marshal(desc)
	return fmt.Sprintf("```12dpl\n%s\n```\n---\n%s", signature, encodedDesc[1:len(encodedDesc)-1])
}
