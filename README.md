# 12d-lang-server

Language server for the 12d programming language (12dPL) conforming to the
[Language Server Protocol (LSP)](https://microsoft.github.io/language-server-protocol/specifications/lsp/3.17/specification/).

## Table of Contents

1. [Dependencies](#dependencies)
2. [Building](#building)
3. [Testing](#testing)
4. [Design Descisions](#design-descisions)
5. [Contributing](#contributing)

## Dependencies

- [Go](https://go.dev/)
- Make
- Python 3

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

## Contributing

You can help the project by contributing in the following ways:

### Patching documentation

Since we get the 12dpl library documentation by parsing the 12d macro manual,
there are a lot of errors in the documentation such as pdf header and footer
text being included in function descriptions, inconsistent function signature
styling, incorrect spacing in sentences and special symbol characters.

You can help improve the quality of the documentation by fixing the above issues
by following the steps outlined in the [12d Documentation
Patching](./doc/4dm/README.md).

### Bugfixes

Contribute to the project directly by fixing bugs and opening a pull request.

### TODO

- [ ] Support reference type func parameters.

    ```12dpl
    Integer Foo(Integer &bar) {}
    ```

- [ ] Support multiple single line declaration.

    ```12dpl
    Integer foo, bar = 1;
    ```
