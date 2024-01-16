.PHONY:
install:
	go install ./cmd/12dls

.PHONY:
build:
	go build ./cmd/12dls

.PHONY:
build-windows:
	GOOS='windows' GOARCH='amd64' go build -o 12dls.exe ./cmd/12dls

.PHONY:
run:
	go run ./main.go

.PHONY:
log:
	tail -f -n 30 /tmp/12d-lang-server.log

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

# Generate the go code that looks up the library items.
.PHONY:
gen-lib:
	@go run ./cmd/gen_lib_doc/main.go ./doc/4dm/generated.json > ./lang/lib.go

.PHONY:
gen-patch:
	@./doc/4dm/mk_patch.py ./doc/4dm/generated.json  ./doc/4dm/patch.json

.PHONY:
vendor-parser:
	@./scripts/vendor_parser.sh ./parser
