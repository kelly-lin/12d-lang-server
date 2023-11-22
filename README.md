# 12d-lang-server

Language server for the 12d programming language (12dPL) conforming to the
Language Server Protocol (LSP).

## Design Descisions

Currently, the language server does not support multiple file support. This
means that it will only analyse and provide services for the current file.

Supports stdio as IPC.
