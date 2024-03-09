package lang

import (
	"errors"
	"strings"
)

func GetReturnType(libFuncDocString string) (string, error) {
	trimmed := strings.TrimPrefix(libFuncDocString, "```12dpl\n")
	split := strings.Split(trimmed, " ")
	if len(split) == 0 {
		return "", errors.New("no return type in library function doc string")
	}
	return split[0], nil
}
