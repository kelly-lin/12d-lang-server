package parser

// #include "parser.h"
// TSLanguage *tree_sitter_pl12d();
import "C"
import (
	"unsafe"

	sitter "github.com/smacker/go-tree-sitter"
)

func GetLanguage() *sitter.Language {
	ptr := unsafe.Pointer(C.tree_sitter_pl12d())
	return sitter.NewLanguage(ptr)
}
