.PHONY:
run:
	go run ./main.go

.PHONY:
build:
	go build
	go build -o ./client ./cmd/client

.PHONY:
log:
	tail -f /tmp/12d-lang-server.log

.PHONY:
test:
	go test ./...
