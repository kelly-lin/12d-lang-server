package parser_test

import (
	"context"
	"testing"

	pl12d "github.com/kelly-lin/12d-lang-server/parser"
	sitter "github.com/smacker/go-tree-sitter"
	"github.com/stretchr/testify/assert"
)

type Point struct {
	Row    uint32
	Column uint32
}

type Range struct {
	Start Point
	End   Point
}

func TestFindDefinition(t *testing.T) {
	assert := assert.New(t)

	sourceCode := []byte(`void main() {}
Integer Foo() {}`)
	n, err := sitter.ParseCtx(context.Background(), sourceCode, pl12d.GetLanguage())
	assert.NoError(err)
	pattern := `(
    (source_file 
        (function_definition
            type: (primitive_type)
            declarator: (function_declarator (identifier) @name)))
    (#eq? @name "Foo")
)`
	q, err := sitter.NewQuery([]byte(pattern), pl12d.GetLanguage())
	assert.NoError(err)
	qc := sitter.NewQueryCursor()
	qc.Exec(q, n)
	want := Range{
		Start: Point{Row: 1, Column: 8},
		End:   Point{Row: 1, Column: 11},
	}
	var got Range
	for {
		m, ok := qc.NextMatch()
		if !ok {
			break
		}
		m = qc.FilterPredicates(m, sourceCode)
		for _, c := range m.Captures {
			start := c.Node.StartPoint()
			got.Start.Row = start.Row
			got.Start.Column = start.Column

			end := c.Node.EndPoint()
			got.End.Row = end.Row
			got.End.Column = end.Column
		}
	}
	assert.Equal(want, got, "not equal")
}
