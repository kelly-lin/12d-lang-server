package parser_test

import (
	"context"
	"testing"

	pl12d "github.com/kelly-lin/12d-lang-server/parser/12dpl"
	sitter "github.com/smacker/go-tree-sitter"
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
