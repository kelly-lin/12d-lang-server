package lang_test

import (
	"bytes"
	"io"
	"os"
	"os/exec"
	"path/filepath"
	"reflect"
	"testing"

	"github.com/stretchr/testify/assert"
)

// Tests if the current lib file is in sync with the generated manual. The lib
// file can be out of sync if patches have been applied but the library code has
// not been regenerated.
func TestGeneratedLib(t *testing.T) {
	assert := assert.New(t)
	cmd := exec.Command(
		"go",
		"run",
		filepath.Join("..", "cmd", "gen_lib_doc", "main.go"),
		filepath.Join("..", "doc", "4dm", "generated.json"),
	)
	output := bytes.NewBuffer(nil)
	cmd.Stdout = output
	err := cmd.Run()
	assert.NoError(err)
	got := output.Bytes()

	assert.NoError(err)
	f, err := os.Open("lib.go")
	assert.NoError(err)
	want, err := io.ReadAll(f)
	assert.NoError(err)

	if !reflect.DeepEqual(want, got) {
		t.Fatal("library and generated manual file are out of sync, regenerate the library file")
	}
}

// Tests to see if the patches have been applied to the generated manual file.
func TestPatchesApplied(t *testing.T) {
	assert := assert.New(t)
	// The output of this command would be the patched documentation.
	cmd := exec.Command(
		"python3",
		filepath.Join("..", "doc", "4dm", "patch_doc.py"),
		filepath.Join("..", "doc", "4dm", "patch.json"),
		filepath.Join("..", "doc", "4dm", "generated.json"),
	)
	output := bytes.NewBuffer(nil)
	cmd.Stdout = output
	err := cmd.Run()
	assert.NoError(err)
	got := output.Bytes()

	// The current documentation file.
	f, err := os.Open(filepath.Join("..", "doc", "4dm", "generated.json"))
	assert.NoError(err)
	want, err := io.ReadAll(f)
	assert.NoError(err)

	if !reflect.DeepEqual(want, got) {
		t.Fatal("generated manual file has not been patched with the latest patches, regenerate the manual file")
	}
}
