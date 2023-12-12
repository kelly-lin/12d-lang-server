package parser_test

import (
	"testing"

	"github.com/kelly-lin/12d-lang-server/parser"
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
		got, err := parser.FindFuncDefinition("Foo", sourceCode)
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
		got, err := parser.FindFuncDefinition("Foo", sourceCode)
		assert.NoError(err)
		assert.Equal(want, got)
	})

	t.Run("should error when no match is found", func(t *testing.T) {
		assert := assert.New(t)
		sourceCode := []byte(`void main() {}`)
		want := parser.Range{}
		got, err := parser.FindFuncDefinition("Foo", sourceCode)
		assert.Equal(want, got)
		assert.EqualError(err, parser.ErrNoDefinition.Error())
	})
}
