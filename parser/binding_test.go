package binding_test

import (
	"context"
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	pl12d "github.com/kelly-lin/12d-lang-server/parser"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n, err := sitter.ParseCtx(context.Background(), []byte("void main() {}"), pl12d.GetLanguage())
	assert.NoError(err)
	assert.Equal(
		"(source_file (function_definition type: (primitive_type) declarator: (function_declarator declarator: (identifier) parameters: (parameter_list)) body: (compound_statement)))",
		n.String(),
	)
}
