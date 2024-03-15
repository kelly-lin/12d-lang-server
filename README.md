# 12d-lang-server

Language server for the 12d programming language (12dPL) conforming to the
[Language Server Protocol (LSP)](https://microsoft.github.io/language-server-protocol/specifications/lsp/3.17/specification/).

## Table of Contents

1. [Dependencies](#dependencies)
2. [Building](#building)
3. [Testing](#testing)
4. [Configuration](#configuration)
5. [Design Decisions](#design-decisions)
6. [Features](#features)
7. [Roadmap](#roadmap)
8. [Contributing](#contributing)

## Dependencies

- [Go](https://go.dev/)
- Make
- Python 3

## Building

Build the language server by executing `make build` which will compile the
language server binary `12dls` in the current directory.

## Testing

Run automated tests by executing `make test`.

## Configuration

The language server can be configured by passing in the below options to the
`12dls` command.

| Option | Description                             | Default Value |
| ------ | --------------------------------------- | ------------- |
| -i     | Path to includes directory.             | `""`          |
| -d     | Enable debugging features like logging. | `false`       |

## Design Decisions

- Currently the language server does not support services across multiple files.
  This means that it will only analyse and provide services for the current file.
- Supports stdio as IPC. stdio is the standard transport for language server IPC
  and is also straight forward to implement.

## Features

- Go to definition.
- Hover support.
  - User defined function documentation in markdown.
- Rename symbol.
- Find references.

## Roadmap

- [x] Go to definition.
- [x] Hover support.
  - [x] User defined function documentation in markdown.
- [x] Rename symbol.
- [x] Find references.
- [ ] Autoformatting.
- [ ] Autocompletion.
- [ ] Includes.
  - [x] Include directory references.
  - [ ] Support relative path includes.

## Contributing

You can help the project by contributing in the following ways:

### Add a feature request

Submit a feature request through opening a [Github issue](https://github.com/kelly-lin/12d-lang-server/issues).
with a [Feature Request] tag in the issue subject. e.g. `[Feature Request]
Autocompletion`.

### Report a bug

Report a bug providing sample source code and a detailed description of the bug
as a [Github issue](https://github.com/kelly-lin/12d-lang-server/issues).

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

## Troubleshooting

- Error when compiling on windows `Cgo: sorry, unimplemented: 64-bit mode not
compiled in`
  You have a c compiler which does not support 32 and 64 bit. Install [tdm-gcc](https://jmeubank.github.io/tdm-gcc/).
  to fix.
