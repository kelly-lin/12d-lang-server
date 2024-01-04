package parser_test

import (
	"context"
	"testing"

	"github.com/kelly-lin/12d-lang-server/parser"
	pl12d "github.com/kelly-lin/12d-lang-server/parser"
	sitter "github.com/smacker/go-tree-sitter"
	"github.com/stretchr/testify/assert"
)

func TestFindDefinition(t *testing.T) {
	t.Run("should find the expected range", func(t *testing.T) {
		assert := assert.New(t)
		sourceCode := []byte(`void main() {}
Integer Foo() {}`)
		want := parser.Range{
			Start: parser.Point{Row: 1, Column: 8},
			End:   parser.Point{Row: 1, Column: 11},
		}
		got, _, err := parser.FindFuncDefinition("Foo", sourceCode)
		assert.NoError(err)
		assert.Equal(want, got)
	})

	t.Run("should return the first definition", func(t *testing.T) {
		assert := assert.New(t)
		sourceCode := []byte(`Integer Foo() {}
Integer Foo() {}`)
		want := parser.Range{
			Start: parser.Point{Row: 0, Column: 8},
			End:   parser.Point{Row: 0, Column: 11},
		}
		got, _, err := parser.FindFuncDefinition("Foo", sourceCode)
		assert.NoError(err)
		assert.Equal(want, got)
	})

	t.Run("should error when no match is found", func(t *testing.T) {
		assert := assert.New(t)
		sourceCode := []byte(`void main() {}`)
		want := parser.Range{}
		got, _, err := parser.FindFuncDefinition("Foo", sourceCode)
		assert.Equal(want, got)
		assert.EqualError(err, parser.ErrNoDefinition.Error())
	})
}

func TestFindIdentifier(t *testing.T) {
	assert := assert.New(t)
	sourceCode := []byte(`Integer Add(Integer addend, Integer augend) {
    return addend + augend;
}

void main() {
    Integer foo = 1;
    Integer bar = 1;
    Integer result = Add(foo, bar);
}`)
	n, err := sitter.ParseCtx(context.Background(), sourceCode, pl12d.GetLanguage())
	assert.NoError(err)
	want := "Add"
	lineNum := 7
	colNum := 21
	node, err := parser.FindIdentifierNode(n, uint(lineNum), uint(colNum))
	assert.NoError(err)
	assert.Equal(want, node.Content(sourceCode))
}
