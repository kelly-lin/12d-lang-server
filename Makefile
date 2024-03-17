.PHONY:
install:
	go install ./cmd/12dls

.PHONY:
build:
	go build -ldflags "-X main.version=$(shell git describe --tags --abbrev=0)" ./cmd/12dls

.PHONY:
build-windows:
	GOOS='windows' GOARCH='amd64' go build -ldflags "-X main.version=$(shell git describe --tags --abbrev=0)" -o 12dls.exe ./cmd/12dls

.PHONY:
run:
	go run ./cmd/12dls

.PHONY:
test:
	go test ./...

.PHONY:
fmt:
	go fmt ./...

# Generate documentation from the 12d programming manual and patch the
# documentation.
.PHONY:
gen-doc:
	@./doc/4dm/gen_doc.py ./doc/4dm/proto_v14.txt ./doc/4dm/12d_progm_v15.txt | ./doc/4dm/patch_doc.py ./doc/4dm/patch.json > ./doc/4dm/generated.json

# Apply patches to generated documentation.
.PHONY:
patch-doc:
	@./doc/4dm/patch_doc.py ./doc/4dm/patch.json ./doc/4dm/generated.json > ./_generated.json
	@mv ./_generated.json ./doc/4dm/generated.json

# Generate the go code that looks up the library items.
.PHONY:
gen-lib:
	@go run ./cmd/gen_lib_doc/main.go ./doc/4dm/generated.json > ./lang/lib.go

.PHONY:
gen-patch:
	@./doc/4dm/mk_patch.py ./doc/4dm/generated.json  ./doc/4dm/patch.json

.PHONY:
vendor-parser-12dpl:
	@./scripts/vendor_parser.sh kelly-lin/tree-sitter-12dpl main ./parser/12dpl

.PHONY:
vendor-parser-doxygen:
	@./scripts/vendor_parser.sh tree-sitter-grammars/tree-sitter-doxygen master ./parser/doxygen
