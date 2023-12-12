package parser_test

import (
	"testing"

	"github.com/kelly-lin/12d-lang-server/parser"
	"github.com/stretchr/testify/assert"
)

func TestFindDefinition(t *testing.T) {
	assert := assert.New(t)
	sourceCode := []byte(`void main() {}
Integer Foo() {}`)
	want := parser.Range{
		Start: parser.Point{Row: 1, Column: 8},
		End:   parser.Point{Row: 1, Column: 11},
	}
	got, err := parser.FindFuncDefinition("Foo", sourceCode)
	assert.NoError(err)
	assert.Equal(want, got, "expected ranges to be equal but was not")
}
