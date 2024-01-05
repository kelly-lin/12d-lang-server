#!/bin/sh
# Vendor in the parser files.

print_usage() {
	printf 'vendor_parser.sh <target_dir>

Arguments:
    target_dir      directory to save parser.c and parser.h files
'
}

if [ -z "$1" ]; then
	echo 'please provide target directory'
	print_usage
	exit 1
fi
if [ ! -d "$1" ]; then
	echo "target directory $1 does not exist"
	exit 1
fi

if ! heads=$(git ls-remote -h --exit-code 'git@github.com:kelly-lin/tree-sitter-12dpl.git'); then
	echo 'could not get repository heads'
	exit 1
fi

commit_hash="$(echo "$heads" | grep 'refs/heads/main' | cut -f1)"
if [ -z "$commit_hash" ]; then
	echo 'could not find main commit hash'
	exit 1
fi

if ! parser_c_content=$(curl -f 'https://raw.githubusercontent.com/kelly-lin/tree-sitter-12dpl/main/src/parser.c'); then
	echo 'could not fetch parser.c'
	exit 1
fi

if ! parser_h_content=$(curl -f 'https://raw.githubusercontent.com/kelly-lin/tree-sitter-12dpl/main/src/tree_sitter/parser.h'); then
	echo 'could not fetch parser.h'
	exit 1
fi

printf '// Vendored commit %s

%s' "$commit_hash" "$(echo "$parser_c_content" | sed 's|^#include <tree_sitter/parser.h>$|#include "parser.h"|')" >"$1/parser.c"

printf '// Vendored commit %s

%s' "$commit_hash" "$parser_h_content" >"$1/parser.h"
