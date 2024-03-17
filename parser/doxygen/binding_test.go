package parser_test

import (
	"context"
	"testing"

	"github.com/kelly-lin/12d-lang-server/parser/doxygen"
	sitter "github.com/smacker/go-tree-sitter"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n, err := sitter.ParseCtx(context.Background(), []byte(`/*!
	\param a an integer argument.
	\param s a constant character pointer.
	\return The test results
	\sa QTstyle_Test(), ~QTstyle_Test(), testMeToo() and publicVar()
*/
`), parser.GetLanguage())
	assert.NoError(err)
	assert.Equal(
		"(document (tag (tag_name) (identifier) (description)) (tag (tag_name) (identifier) (description)) (tag (tag_name) (description)) (tag (tag_name) function: (function_link) function: (function_link) function: (function_link) (_text) function: (function_link)))",
		n.String(),
	)
}
