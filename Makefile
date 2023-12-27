.PHONY:
run:
	go run ./main.go

.PHONY:
build:
	go build ./cmd/12dls

.PHONY:
log:
	tail -f -n 30 /tmp/12d-lang-server.log

.PHONY:
test:
	go test ./...

.PHONY:
fmt:
	go fmt ./...

.PHONY:
gendoc:
	@python3 ./doc/4dm/gen_doc.py ./doc/4dm/proto_v14.txt ./doc/4dm/12d_progm_v15.txt ./doc/4dm/patch.json > ./doc/4dm/generated.json
