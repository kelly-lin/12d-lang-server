package protocol_test

import (
	"github.com/kelly-lin/12d-lang-server/protocol"
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestURI(t *testing.T) {
	assert := assert.New(t)
	type TestCase struct {
		Filepath string
		Want     string
	}
	testCases := []TestCase{
		{
			Filepath: "/foo/bar/baz",
			Want:     "file:///foo/bar/baz",
		},
		{
			Filepath: "C:\\Program Files\\12d\\12dmodel\\14.00\\set_ups/set_ups.h",
			Want:     "file:///C:/Program Files/12d/12dmodel/14.00/set_ups/set_ups.h",
		},
	}
	for _, testCase := range testCases {
		assert.Equal(testCase.Want, protocol.URI(testCase.Filepath))
	}
}
