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
