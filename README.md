# 12d-lang-server

Language server for the 12d programming language (12dPL) conforming to the
[Language Server Protocol (LSP)](https://microsoft.github.io/language-server-protocol/specifications/lsp/3.17/specification/).

## Table of Contents

1. [Dependencies](#dependencies)
2. [Building](#building)
3. [Testing](#testing)
4. [Design Descisions](#design-descisions)

## Dependencies

- [Go](https://go.dev/)
- make

## Building

Build the language server by executing `make build` which will compile the
language server binary `12dls` in the current directory.

## Testing

Run automated tests by executing `make test`.

## Design Descisions

- Currently the language server does not support services across multiple files.
  This means that it will only analyse and provide services for the current file.
- Supports stdio as IPC. stdio is the standard transport for language server IPC
  and is also straight forward to implement.
