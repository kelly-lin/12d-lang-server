package server_test

import (
	"bufio"
	"encoding/json"
	"fmt"
	"io"
	"os"
	"regexp"
	"strconv"
	"strings"
	"testing"

	"go.uber.org/goleak"

	"github.com/kelly-lin/12d-lang-server/protocol"
	"github.com/kelly-lin/12d-lang-server/server"
	"github.com/stretchr/testify/assert"
	"github.com/stretchr/testify/require"
)

func TestServer(t *testing.T) {
	mustNewLocationResponseMessage := func(start, end protocol.Position) protocol.ResponseMessage {
		msg, err := newLocationResponseMessage(1, "file:///foo.4dm", start, end)
		assert.NoError(t, err)
		return msg
	}

	t.Run("textDocument/definition", func(t *testing.T) {
		// Helper returns the response message and fails if the test if the
		// response message could not be created.
		type TestCase struct {
			Desc       string
			SourceCode string
			Pos        protocol.Position
			Want       protocol.ResponseMessage
		}
		testCases := []TestCase{
			{
				Desc: "func identifier",
				SourceCode: `Integer Add(Integer augend, Integer addend) {
    return augend + addend;
}

void main() {
    Integer result = Add(1, 2);
}`,
				Pos: protocol.Position{Line: 5, Character: 21},
				Want: mustNewLocationResponseMessage(
					protocol.Position{Line: 0, Character: 8},
					protocol.Position{Line: 0, Character: 11},
				),
			},
			{
				Desc: "func parameter identifier",
				SourceCode: `Integer Add(Integer augend, Integer addend) {
	Text foo = "\"hello\""
    return augend + addend;
}

void main() {
    Integer augend = 1;
    Integer addend = 1;
}`,
				Pos: protocol.Position{Line: 2, Character: 11},
				Want: mustNewLocationResponseMessage(
					protocol.Position{Line: 0, Character: 20},
					protocol.Position{Line: 0, Character: 26},
				),
			},
			{
				Desc: "func parameter identifier in multiline parameter list",
				SourceCode: `Integer Add(
    Integer augend,
    Integer addend
) {
    return augend + addend;
}`,
				Pos: protocol.Position{Line: 4, Character: 11},
				Want: mustNewLocationResponseMessage(
					protocol.Position{Line: 1, Character: 12},
					protocol.Position{Line: 1, Character: 18},
				),
			},
			{
				Desc: "func pointer parameter",
				SourceCode: `void SetABC(Dynamic_Text &dt) {
    Set_item(dt, 1, "abc");
}`,
				Pos: protocol.Position{Line: 1, Character: 13},
				Want: mustNewLocationResponseMessage(
					protocol.Position{Line: 0, Character: 26},
					protocol.Position{Line: 0, Character: 28},
				),
			},
			{
				Desc: "binary expression local variable",
				SourceCode: `Integer Add_one(Integer addend) {
    Integer augend = 1;
    return augend + addend;
}`,
				Pos: protocol.Position{Line: 2, Character: 11},
				Want: mustNewLocationResponseMessage(
					protocol.Position{Line: 1, Character: 12},
					protocol.Position{Line: 1, Character: 18},
				),
			},
			{
				Desc: "local variable",
				SourceCode: `Integer One() {
    Integer result = 1;
    return result;
}`,
				Pos: protocol.Position{Line: 2, Character: 11},
				Want: mustNewLocationResponseMessage(
					protocol.Position{Line: 1, Character: 12},
					protocol.Position{Line: 1, Character: 18},
				),
			},
			{
				Desc: "local variable inside for loop",
				SourceCode: `Integer Looper() {
    for (Integer i = 1; i <= 10; i++) {
        Integer j = i;
    }
}`,
				Pos: protocol.Position{Line: 2, Character: 20},
				Want: mustNewLocationResponseMessage(
					protocol.Position{Line: 1, Character: 17},
					protocol.Position{Line: 1, Character: 18},
				),
			},
			{
				Desc: "local variable outside for loop",
				SourceCode: `Integer Looper() {
    Integer k = 1;
    for (Integer i = 1; i <= 10; i++) {
        Integer j = k;
    }
}`,
				Pos: protocol.Position{Line: 3, Character: 20},
				Want: mustNewLocationResponseMessage(
					protocol.Position{Line: 1, Character: 12},
					protocol.Position{Line: 1, Character: 13},
				),
			},
			{
				Desc: "local variable inside for loop",
				SourceCode: `Integer Looper() {
    for (Integer i = 1; i <= 10; i++) {
        Integer k = 1;
        Integer j = k;
    }
}`,
				Pos: protocol.Position{Line: 3, Character: 20},
				Want: mustNewLocationResponseMessage(
					protocol.Position{Line: 2, Character: 16},
					protocol.Position{Line: 2, Character: 17},
				),
			},
			{
				Desc: "declaration without initialisation",
				SourceCode: `void Validate_source_box(Source_Box source_box) {
    Dynamic_Element elts;
    Validate(source_box, elts);
}`,
				Pos: protocol.Position{Line: 2, Character: 25},
				Want: mustNewLocationResponseMessage(
					protocol.Position{Line: 1, Character: 20},
					protocol.Position{Line: 1, Character: 24},
				),
			},
			{
				Desc: "preproc definition",
				SourceCode: `#define DEBUG 1

void main() {
    if (DEBUG) {
        Print("debug");
    }
}`,
				Pos: protocol.Position{Line: 3, Character: 8},
				Want: mustNewLocationResponseMessage(
					protocol.Position{Line: 0, Character: 8},
					protocol.Position{Line: 0, Character: 13},
				),
			},
			{
				Desc: "global scope",
				SourceCode: `{
    Integer AREA_CODE = 10;
}

void main() {
    Integer result = AREA_CODE + 1;
}`,
				Pos: protocol.Position{Line: 5, Character: 21},
				Want: mustNewLocationResponseMessage(
					protocol.Position{Line: 1, Character: 12},
					protocol.Position{Line: 1, Character: 21},
				),
			},
			{
				Desc: "multiple declaration - first var with initialisation",
				SourceCode: `void main() {
    Real x = 1, y;
    Point pt;
    Set_x(pt, x);
    Set_y(pt, y);
}`,
				Pos: protocol.Position{Line: 3, Character: 14},
				Want: mustNewLocationResponseMessage(
					protocol.Position{Line: 1, Character: 9},
					protocol.Position{Line: 1, Character: 10},
				),
			},
			{
				Desc: "multiple declaration - second var without initialisation",
				SourceCode: `void main() {
    Real x = 1, y;
    Point pt;
    Set_x(pt, x);
    Set_y(pt, y);
}`,
				Pos: protocol.Position{Line: 4, Character: 14},
				Want: mustNewLocationResponseMessage(
					protocol.Position{Line: 1, Character: 16},
					protocol.Position{Line: 1, Character: 17},
				),
			},
		}
		for _, testCase := range testCases {
			t.Run(testCase.Desc, func(t *testing.T) {
				defer goleak.VerifyNone(t)
				assert := assert.New(t)
				logger, err := newLogger()
				assert.NoError(err)
				in, out, cleanUp := startServer(logger)
				defer cleanUp()

				var id int64 = 1
				didOpenMsgBytes, err := newDidOpenRequestMessageBytes(id, "file:///foo.4dm", testCase.SourceCode)
				assert.NoError(err)
				_, err = in.Writer.Write([]byte(server.ToProtocolMessage(didOpenMsgBytes)))
				assert.NoError(err)

				definitionMsgBytes, err := newDefinitionRequestMessageBytes(id, "file:///foo.4dm", testCase.Pos)
				assert.NoError(err)
				_, err = in.Writer.Write([]byte(server.ToProtocolMessage(definitionMsgBytes)))
				assert.NoError(err)

				got, err := getReponseMessage(out.Reader)
				assert.NoError(err)
				assertResponseMessageEqual(t, testCase.Want, got)
			})
		}
	})

	// This is essentially a go to definition test but the source gets updated]
	// after the initial did open request.
	t.Run("textDocument/didChange", func(t *testing.T) {
		// TODO: clean up this test.
		defer goleak.VerifyNone(t)
		assert := assert.New(t)
		logger, err := newLogger()
		assert.NoError(err)
		in, out, cleanUp := startServer(logger)
		defer cleanUp()

		sourceCodeOnOpen := `void main() {
    Add(1, 1);
}`
		var openRequestID int64 = 1
		didOpenMsgBytes, err := newDidOpenRequestMessageBytes(openRequestID, "file:///foo.4dm", sourceCodeOnOpen)
		assert.NoError(err)
		_, err = in.Writer.Write([]byte(server.ToProtocolMessage(didOpenMsgBytes)))
		assert.NoError(err)

		pos1 := protocol.Position{Line: 1, Character: 4}
		var defintionRequestID1 int64 = 2
		definitionMsg1Bytes, err := newDefinitionRequestMessageBytes(defintionRequestID1, "file:///foo.4dm", pos1)
		assert.NoError(err)
		_, err = in.Writer.Write([]byte(server.ToProtocolMessage(definitionMsg1Bytes)))
		assert.NoError(err)

		// We should receive a no definition result here since the did open
		// request source code does not yet have the function defined.
		got, err := getReponseMessage(out.Reader)
		assert.NoError(err)
		wantOnOpen := protocol.ResponseMessage{ID: defintionRequestID1, Result: []byte("null"), Error: nil}
		assertResponseMessageEqual(t, wantOnOpen, got)

		// Source code got updated.
		sourceCodeOnChange := `Integer Add(Integer addend, Integer augend) {
    return addend, augend;
}

void main() {
    Add(1, 1);
}`
		var onChangeID int64 = 3
		didChangeMsgBytes, err := newDidChangeRequestMessageBytes(onChangeID, "file:///foo.4dm", sourceCodeOnChange)
		assert.NoError(err)
		_, err = in.Writer.Write([]byte(server.ToProtocolMessage(didChangeMsgBytes)))
		assert.NoError(err)

		var definitionRequestID2 int64 = 1
		pos2 := protocol.Position{Line: 5, Character: 4}
		definitionMsg2Bytes, err := newDefinitionRequestMessageBytes(definitionRequestID2, "file:///foo.4dm", pos2)
		assert.NoError(err)
		_, err = in.Writer.Write([]byte(server.ToProtocolMessage(definitionMsg2Bytes)))
		assert.NoError(err)

		// The new source code now has the definition for the function.
		got, err = getReponseMessage(out.Reader)
		assert.NoError(err)
		want := mustNewLocationResponseMessage(
			protocol.Position{Line: 0, Character: 8},
			protocol.Position{Line: 0, Character: 11},
		)
		assertResponseMessageEqual(t, want, got)
	})

	t.Run("textDocument/hover", func(t *testing.T) {
		type TestCase struct {
			Desc       string
			SourceCode string
			Position   protocol.Position
			Pattern    []string
		}

		t.Run("library funcs", func(t *testing.T) {
			createFuncSignaturePattern := func(name string, types []string) string {
				result := ""
				for idx, t := range types {
					if idx == 0 {
						result = fmt.Sprintf(`%s\s*&?\w+`, t)
						continue
					}
					result = fmt.Sprintf(`%s,\s*%s\s*&?\w+`, result, t)
				}
				if result != "" {
					result = fmt.Sprintf(`%s\(%s\)`, name, result)
				}
				return result
			}
			testCases := []TestCase{
				{
					Desc: "all local declarations args",
					SourceCode: `void main() {
	Dynamic_Element elts;
	Integer i = 1;
	Element elt;
	Set_item(elts, i, elt);
}`,
					Position: protocol.Position{Line: 4, Character: 4},
					Pattern:  []string{createFuncSignaturePattern("Set_item", []string{"Dynamic_Element", "Integer", "Element"})},
				},
				{
					Desc: "inline literals args",
					SourceCode: `void main() {
	Named_Tick_Box clean_tick_box = Create_named_tick_box("Clean", 0, "cmd_clean");
}`,
					Position: protocol.Position{Line: 1, Character: 36},
					Pattern:  []string{createFuncSignaturePattern("Create_named_tick_box", []string{"Text", "Integer", "Text"})},
				},
				{
					Desc: "preproc defs args",
					SourceCode: `#define ALL_WIDGETS_OWN_HEIGHT 2
void main() {
	Vertical_Group group = Create_vertical_group(ALL_WIDGETS_OWN_HEIGHT);
}`,
					Position: protocol.Position{Line: 2, Character: 27},
					Pattern:  []string{createFuncSignaturePattern("Create_vertical_group", []string{"Integer"})},
				},
				{
					Desc: "local declaration, string and number literal preproc defs",
					SourceCode: `#define ATT_NUM 1
#define ATT_NAME "name"
void main() {
	Attributes atts;
	Attribute_exists(atts, ATT_NAME, ATT_NUM);
}`,
					Position: protocol.Position{Line: 4, Character: 4},
					Pattern:  []string{createFuncSignaturePattern("Attribute_exists", []string{"Attributes", "Text", "Integer"})},
				},
				{
					Desc: "func param args",
					SourceCode: `void GetFirstItem(Dynamic_Text items) {
	Text result = "";
	Get_item(items, 1, result);
	return result;
}`,
					Position: protocol.Position{Line: 2, Character: 4},
					Pattern:  []string{createFuncSignaturePattern("Get_item", []string{"Dynamic_Text", "Integer", "Text"})},
				},
				{
					Desc: "func reference param args",
					SourceCode: `void GetFirstItem(Dynamic_Text &items) {
	Text result = "";
	Get_item(items, 1, result);
	return result;
}`,
					Position: protocol.Position{Line: 2, Character: 4},
					Pattern:  []string{createFuncSignaturePattern("Get_item", []string{"Dynamic_Text", "Integer", "Text"})},
				},
				{
					Desc: "Colour_Message_Box and Message_Box polymorphism - match with Message_Box signature",
					SourceCode: `void main() {
	Colour_Message_Box msg_box = Create_colour_message_box("");
	Create_input_box("Name", msg_box);
}`,
					Position: protocol.Position{Line: 2, Character: 4},
					Pattern:  []string{createFuncSignaturePattern("Create_input_box", []string{"Text", "Message_Box"})},
				},
				{
					Desc: "Colour_Message_Box and Message_Box polymorphism - match with Colour_Message_Box signature",
					SourceCode: `void main() {
    Colour_Message_Box msg_box = Create_colour_message_box("");
    Set_data(msg_box, "hello");
}`,
					Position: protocol.Position{Line: 2, Character: 4},
					Pattern: []string{
						createFuncSignaturePattern("Set_data", []string{"Colour_Message_Box", "Text"}),
						createFuncSignaturePattern("Set_data", []string{"Message_Box", "Text"}),
					},
				},
				{
					Desc: "File box as widget polymorhpism",
					SourceCode: `void main() {
	File_Box filebox;
	Set_width_in_chars(filebox, 10);
}`,
					Position: protocol.Position{Line: 2, Character: 4},
					Pattern:  []string{createFuncSignaturePattern("Set_width_in_chars", []string{"Widget", "Integer"})},
				},
				{
					Desc: "binary expression in arg list - variable",
					SourceCode: `void main() {
    Integer length = 1;
    Get_subtext("hello world", 1, length - 1);
}`,
					Position: protocol.Position{Line: 2, Character: 4},
					Pattern:  []string{createFuncSignaturePattern("Get_subtext", []string{"Text", "Integer", "Integer"})},
				},
				{
					Desc: "binary expression in arg list - number literal",
					SourceCode: `void main() {
    Get_subtext("hello world", 1, 2 - 1);
}`,
					Position: protocol.Position{Line: 1, Character: 4},
					Pattern:  []string{createFuncSignaturePattern("Get_subtext", []string{"Text", "Integer", "Integer"})},
				},
				{
					Desc: "binary expression in arg list - string literal",
					SourceCode: `void main() {
    Get_subtext("hello" + " " + "world", 1, 2 - 1);
}`,
					Position: protocol.Position{Line: 1, Character: 4},
					Pattern:  []string{createFuncSignaturePattern("Get_subtext", []string{"Text", "Integer", "Integer"})},
				},
				// TODO: Real in binary expession.
				// TODO: Set_ups.h constants.
				// TODO: Arrays in lib func args
				//     Text scopes[2];
				//     scopes[1] = "root";
				//     scopes[2] = "full tree";
				//     Set_data(scopeChoiceBox,2,scopes); // No def on hover on Set_data.
				//     Set_data(scopeChoiceBox,scopes[1]); // No def on hover on Set_data.
			}
			for _, testCase := range testCases {
				t.Run(testCase.Desc, func(t *testing.T) {
					defer goleak.VerifyNone(t)
					assert := assert.New(t)
					logger, err := newLogger()
					assert.NoError(err)
					in, out, cleanUp := startServer(logger)
					defer cleanUp()

					var openRequestID int64 = 1
					didOpenMsgBytes, err := newDidOpenRequestMessageBytes(openRequestID, "file:///foo.4dm", testCase.SourceCode)
					assert.NoError(err)
					_, err = in.Writer.Write([]byte(server.ToProtocolMessage(didOpenMsgBytes)))
					assert.NoError(err)

					var hoverRequestID int64 = 2
					hoverMsgBytes, err := newHoverRequestMessageBytes(hoverRequestID, "file:///foo.4dm", testCase.Position)
					assert.NoError(err)
					_, err = in.Writer.Write([]byte(server.ToProtocolMessage(hoverMsgBytes)))
					assert.NoError(err)

					got, err := getReponseMessage(out.Reader)
					assert.NoError(err)

					// TODO: refactor this test, the error message is not great.
					var gotHoverResult protocol.Hover
					err = json.Unmarshal(got.Result, &gotHoverResult)
					assert.NoError(err)
					require.Len(t, gotHoverResult.Contents, len(testCase.Pattern))
					for _, pattern := range testCase.Pattern {
						found := false
						c := ""
						for _, content := range gotHoverResult.Contents {
							c = content
							matched, err := regexp.MatchString(pattern, content)
							assert.NoError(err)
							if matched {
								found = true
								break
							}
						}
						assert.True(found, fmt.Sprintf("expected lib item doc to match signature pattern %s but did not: %s", pattern, c))
					}
				})
			}
		})

		t.Run("declarations", func(t *testing.T) {
			testCases := []TestCase{
				{
					Desc: "local initialised var",
					SourceCode: `Integer AddOne(Integer addend) {
    Integer augend = 1;
    return addend, augend;
}`,
					Position: protocol.Position{Line: 2, Character: 19},
					Pattern:  []string{"```12dpl\nInteger augend\n```"},
				},
				{
					Desc: "no definition for identifier declared after usage",
					SourceCode: `void main() {
    Print(text);
	Text text = "Hello world";
}`,
					Position: protocol.Position{Line: 1, Character: 10},
					Pattern:  []string{},
				},
				{
					Desc: "local uninitialised var",
					SourceCode: `Integer AddOne(Integer addend) {
    Integer augend;
	augend = 1;
    return addend, augend;
}`,
					Position: protocol.Position{Line: 3, Character: 19},
					Pattern:  []string{"```12dpl\nInteger augend\n```"},
				},
				{
					Desc: "static array",
					SourceCode: `void main() {
    Text arr[3];
}`,
					Position: protocol.Position{Line: 1, Character: 9},
					Pattern:  []string{"```12dpl\nText arr[]\n```"},
				},
				{
					Desc: "func param",
					SourceCode: `Integer Identity(Integer id) {
    return id;
}`,
					Position: protocol.Position{Line: 1, Character: 11},
					Pattern:  []string{"```12dpl\n(parameter) Integer id\n```"},
				},
				{
					Desc: "multiple variable declaration - initialised var",
					SourceCode: `Integer Two() {
    Integer a = 1, b;
    return a + b;
}`,
					Position: protocol.Position{Line: 2, Character: 11},
					Pattern:  []string{"```12dpl\nInteger a\n```"},
				},
				{
					Desc: "multiple variable declaration - uninitialised var",
					SourceCode: `Integer Two() {
    Integer a = 1, b;
    return a + b;
}`,
					Position: protocol.Position{Line: 2, Character: 15},
					Pattern:  []string{"```12dpl\nInteger b\n```"},
				},
				{
					Desc: "reference param hover in local scope",
					SourceCode: `void Identity(Dynamic_Text &items) {
    return items;
}`,
					Position: protocol.Position{Line: 1, Character: 11},
					Pattern:  []string{"```12dpl\n(parameter) Dynamic_Text &items\n```"},
				},
				{
					Desc: "user defined func - no doc",
					SourceCode: `void Hello() {
    Print("hello\n");
}

void Forever(Integer subject) {
    return Forever(subject);
}`,
					Position: protocol.Position{Line: 5, Character: 11},
					Pattern:  []string{"```12dpl\nvoid Forever(Integer subject)\n```"},
				},
				{
					Desc: "user defined func - poorly formatted multi line parameter list",
					SourceCode: `void SomeFunc(    Text a,
	Text b,
         Integer c
) {
    return SomeFunc(a, b);
}`,
					Position: protocol.Position{Line: 4, Character: 11},
					Pattern:  []string{"```12dpl\nvoid SomeFunc(Text a, Text b, Integer c)\n```"},
				},
				{
					Desc: "user defined func - multi line parameter list with comment",
					SourceCode: `// This function does nothing.
void SomeFunc(
    Text a,
    Integer b
) {
    return SomeFunc(a, b);
}`,
					Position: protocol.Position{Line: 5, Character: 11},
					Pattern:  []string{"```12dpl\nvoid SomeFunc(Text a, Integer b)\n```\n---\nThis function does nothing."},
				},
				{
					Desc: "user defined func - single line doc",
					SourceCode: `// Loops forever.
void Forever(Integer subject) {
    return Forever(subject);
}`,
					Position: protocol.Position{Line: 2, Character: 11},
					Pattern:  []string{"```12dpl\nvoid Forever(Integer subject)\n```\n---\nLoops forever."},
				},
				{
					Desc: "user defined func - single line comment not a doc if not directly above definition",
					SourceCode: `// Loops forever.

void Forever(Integer subject) {
    return Forever(subject);
}`,
					Position: protocol.Position{Line: 3, Character: 11},
					Pattern:  []string{"```12dpl\nvoid Forever(Integer subject)\n```"},
				},
				{
					Desc: "user defined func - multiline comment not a doc if not directly above definition",
					SourceCode: `/* 
    Loops forever
*/.

void Forever(Integer subject) {
    return Forever(subject);
}`,
					Position: protocol.Position{Line: 5, Character: 11},
					Pattern:  []string{"```12dpl\nvoid Forever(Integer subject)\n```"},
				},
				{
					Desc: "user defined func - multi line doc",
					SourceCode: `/*
    Loops forever.
    subject is an integer.
*/
void Forever(Integer subject) {
    return Forever(subject);
}`,
					Position: protocol.Position{Line: 5, Character: 11},
					Pattern:  []string{"```12dpl\nvoid Forever(Integer subject)\n```\n---\nLoops forever.\nsubject is an integer."},
				},
				{
					Desc: "user defined func - single line doc - on definition",
					SourceCode: `void Forever(Integer subject) {
    return Forever(subject);
}`,
					Position: protocol.Position{Line: 0, Character: 5},
					Pattern:  []string{"```12dpl\nvoid Forever(Integer subject)\n```"},
				},
				{
					Desc: "user defined func - single line doc - on definition with doc",
					SourceCode: `// Loops forever.
void Forever(Integer subject) {
    return Forever(subject);
}`,
					Position: protocol.Position{Line: 1, Character: 5},
					Pattern:  []string{"```12dpl\nvoid Forever(Integer subject)\n```\n---\nLoops forever."},
				},
			}
			for _, testCase := range testCases {
				t.Run(testCase.Desc, func(t *testing.T) {
					defer goleak.VerifyNone(t)
					assert := assert.New(t)
					logger, err := newLogger()
					assert.NoError(err)
					in, out, cleanUp := startServer(logger)
					defer cleanUp()

					var openRequestID int64 = 1
					didOpenMsgBytes, err := newDidOpenRequestMessageBytes(openRequestID, "file:///foo.4dm", testCase.SourceCode)
					assert.NoError(err)
					_, err = in.Writer.Write([]byte(server.ToProtocolMessage(didOpenMsgBytes)))
					assert.NoError(err)

					var hoverRequestID int64 = 2
					hoverMsgBytes, err := newHoverRequestMessageBytes(hoverRequestID, "file:///foo.4dm", testCase.Position)
					assert.NoError(err)
					_, err = in.Writer.Write([]byte(server.ToProtocolMessage(hoverMsgBytes)))
					assert.NoError(err)

					got, err := getReponseMessage(out.Reader)
					assert.NoError(err)

					var gotHoverResult protocol.Hover
					err = json.Unmarshal(got.Result, &gotHoverResult)
					assert.NoError(err)
					require.Len(t, gotHoverResult.Contents, len(testCase.Pattern))
					for _, pattern := range testCase.Pattern {
						found := false
						for _, content := range gotHoverResult.Contents {
							if pattern == content {
								found = true
								break
							}
						}
						assert.True(found, strconv.Quote(fmt.Sprintf("wanted %s to be in contents %s but was not", pattern, gotHoverResult.Contents)))
					}
				})
			}
		})
	})
}

func assertResponseMessageEqual(t *testing.T, want, got protocol.ResponseMessage) {
	t.Helper()
	assert.Equal(t, want.ID, got.ID)
	assert.Equal(t, want.Error, got.Error)
	assert.Equal(t, string(want.Result), string(got.Result))
}

// Creates a new protocol request message with definition params and returns the
// wire representation.
func newDefinitionRequestMessageBytes(id int64, uri string, position protocol.Position) ([]byte, error) {
	definitionParams := protocol.DefinitionParams{
		TextDocumentPositionParams: protocol.TextDocumentPositionParams{
			TextDocument: protocol.TextDocumentIdentifier{
				URI: uri,
			},
			Position: position,
		},
	}
	definitionParamsBytes, err := json.Marshal(definitionParams)
	if err != nil {
		return nil, err
	}
	definitionMsg := protocol.RequestMessage{
		JSONRPC: "2.0",
		ID:      id,
		Method:  "textDocument/definition",
		Params:  json.RawMessage(definitionParamsBytes),
	}
	definitionMsgBytes, err := json.Marshal(definitionMsg)
	if err != nil {
		return nil, err
	}
	return definitionMsgBytes, nil
}

func newHoverRequestMessageBytes(id int64, uri string, position protocol.Position) ([]byte, error) {
	hoverParams := protocol.HoverParams{
		TextDocumentPositionParams: protocol.TextDocumentPositionParams{
			TextDocument: protocol.TextDocumentIdentifier{
				URI: uri,
			},
			Position: position,
		},
	}
	hoverParamsBytes, err := json.Marshal(hoverParams)
	if err != nil {
		return nil, err
	}
	hoverMsg := protocol.RequestMessage{
		JSONRPC: "2.0",
		ID:      id,
		Method:  "textDocument/hover",
		Params:  json.RawMessage(hoverParamsBytes),
	}
	hoverMsgBytes, err := json.Marshal(hoverMsg)
	if err != nil {
		return nil, err
	}
	return hoverMsgBytes, nil
}

func newDidOpenRequestMessageBytes(id int64, uri, text string) ([]byte, error) {
	didOpenParams := protocol.DidOpenTextDocumentParams{
		TextDocument: protocol.TextDocumentItem{
			URI:        uri,
			LanguageID: "12dpl",
			Text:       text,
		},
	}
	didOpenParamsBytes, err := json.Marshal(didOpenParams)
	if err != nil {
		return nil, err
	}
	didOpenMsg := protocol.RequestMessage{
		JSONRPC: "2.0",
		ID:      id,
		Method:  "textDocument/didOpen",
		Params:  json.RawMessage(didOpenParamsBytes),
	}
	didOpenMsgBytes, err := json.Marshal(didOpenMsg)
	if err != nil {
		return nil, err
	}
	return didOpenMsgBytes, nil
}

func newDidChangeRequestMessageBytes(id int64, uri, text string) ([]byte, error) {
	didChangeParams := protocol.DidChangeTextDocumentParams{
		TextDocument: protocol.VersionedTextDocumentIdentifier{
			Version: 1,
			TextDocumentIdentifier: protocol.TextDocumentIdentifier{
				URI: uri,
			},
		},
		ContentChanges: []protocol.TextDocumentContentChangeEvent{
			{
				Text: text,
			},
		},
	}
	didChangeParamsBytes, err := json.Marshal(didChangeParams)
	if err != nil {
		return nil, err
	}
	didChangeMsg := protocol.RequestMessage{
		JSONRPC: "2.0",
		ID:      id,
		Method:  "textDocument/didChange",
		Params:  json.RawMessage(didChangeParamsBytes),
	}
	didChangeMsgBytes, err := json.Marshal(didChangeMsg)
	if err != nil {
		return nil, err
	}
	return didChangeMsgBytes, nil
}

// Creates a new protocol response message with definition location and returns
// the wire representation.
func newLocationResponseMessage(id int64, uri string, start, end protocol.Position) (protocol.ResponseMessage, error) {
	locationBytes, err := json.Marshal(protocol.Location{
		URI:   uri,
		Range: protocol.Range{Start: start, End: end},
	})
	if err != nil {
		return protocol.ResponseMessage{}, err
	}
	msg := protocol.ResponseMessage{ID: id, Result: json.RawMessage(locationBytes)}
	return msg, nil
}

// Creates a new logging function for debugging.
func newLogger() (func(msg string), error) {
	file, err := os.Create("/tmp/server_test.txt")
	if err != nil {
		return nil, err
	}
	logger := func(msg string) {
		_, _ = file.WriteString(msg)
	}
	return logger, nil
}

// Starts the language server in a goroutine and returns the input pipe, output
// pipe and a clean up function.
func startServer(logger func(msg string)) (Pipe, Pipe, func()) {
	serv := server.NewServer(logger)
	inReader, inWriter := io.Pipe()
	outReader, outWriter := io.Pipe()
	go (func() {
		if err := serv.Serve(inReader, outWriter); err != nil {
			logger(fmt.Sprintf("%s\n", err))
			return
		}
	})()
	cleanUp := func() {
		inReader.Close()
		inWriter.Close()
		outReader.Close()
		outWriter.Close()
	}
	return Pipe{Reader: inReader, Writer: inWriter},
		Pipe{Reader: outReader, Writer: outWriter},
		cleanUp
}

type Pipe struct {
	Reader *io.PipeReader
	Writer *io.PipeWriter
}

// Reads a single message from reader returns the parsed response message.
func getReponseMessage(rd io.Reader) (protocol.ResponseMessage, error) {
	r := bufio.NewReader(rd)
	line, err := r.ReadString('\n')
	if err != nil {
		return protocol.ResponseMessage{}, err
	}
	numBytesString := strings.TrimPrefix(line, "Content-Length: ")
	numBytes, err := strconv.Atoi(strings.TrimSpace(numBytesString))
	if err != nil {
		return protocol.ResponseMessage{}, err
	}
	_, err = r.ReadString('\n')
	if err != nil {
		return protocol.ResponseMessage{}, err
	}
	msgBytes := make([]byte, numBytes)
	_, _ = io.ReadFull(r, msgBytes)
	if err != nil {
		return protocol.ResponseMessage{}, err
	}
	var msg protocol.ResponseMessage
	if err := json.Unmarshal(msgBytes, &msg); err != nil {
		return protocol.ResponseMessage{}, err
	}
	return msg, nil
}
