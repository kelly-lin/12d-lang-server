package parser

import (
	"context"
	"fmt"

	sitter "github.com/smacker/go-tree-sitter"
)

type Point struct {
	Row    uint32
	Column uint32
}

type Range struct {
	Start Point
	End   Point
}

func FindFuncDefinition(identifier string, source []byte) (Range, error) {
	n, err := sitter.ParseCtx(context.Background(), source, GetLanguage())
    if err != nil {
        return Range{}, err
    }

	pattern := fmt.Sprintf(`(
    (source_file 
        (function_definition
            type: (primitive_type)
            declarator: (function_declarator (identifier) @name)))
    (#eq? @name %q)
)`, identifier)
	q, err := sitter.NewQuery([]byte(pattern), GetLanguage())
    if err != nil {
        return Range{}, err
    }

	qc := sitter.NewQueryCursor()
	qc.Exec(q, n)
	var result Range
	for {
		m, ok := qc.NextMatch()
		if !ok {
			break
		}
		m = qc.FilterPredicates(m, source)
		for _, c := range m.Captures {
			start := c.Node.StartPoint()
			result.Start.Row = start.Row
			result.Start.Column = start.Column

			end := c.Node.EndPoint()
			result.End.Row = end.Row
            result.End.Column = end.Column
		}
	}
    return result, nil
}
