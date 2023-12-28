package lang_test

import (
	"bytes"
	"io"
	"os"
	"os/exec"
	"path"
	"reflect"
	"testing"

	"github.com/stretchr/testify/assert"
)

// Tests if the current lib file is in sync with the generated manual. The lib
// file can be out of sync if patches have been applied but the library code has
// not been regenerated.
func TestGeneratedLib(t *testing.T) {
	assert := assert.New(t)
	wd, err := os.Getwd()
	assert.NoError(err)
	cmd := exec.Command("go", "run", path.Join(wd, "../cmd/gen_lib_doc/main.go"), path.Join(wd, "../doc/4dm/generated.json"))
	output := bytes.NewBuffer(nil)
	cmd.Stdout = output
	err = cmd.Run()
	assert.NoError(err)
	got := output.Bytes()

	assert.NoError(err)
	f, err := os.Open(path.Join(wd, "lib.go"))
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
	wd, err := os.Getwd()
	assert.NoError(err)
	cmd := exec.Command(
		"python3",
		path.Join(wd, "../doc/4dm/gen_doc.py"),
		path.Join(wd, "../doc/4dm/proto_v14.txt"),
		path.Join(wd, "../doc/4dm/12d_progm_v15.txt"),
		path.Join(wd, "../doc/4dm/patch.json"),
	)
	output := bytes.NewBuffer(nil)
	cmd.Stdout = output
	err = cmd.Run()
	assert.NoError(err)
	got := output.Bytes()

	f, err := os.Open(path.Join(wd, "../doc/4dm/generated.json"))
	want, err := io.ReadAll(f)
	assert.NoError(err)

	if !reflect.DeepEqual(want, got) {
		t.Fatal("generated manual file has not been patched with the latest patches, regenerate the manual file")
	}
}
