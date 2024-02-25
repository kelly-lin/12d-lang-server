#!/bin/sh
# Vendor in the parser files from https://github.com/kelly-lin/tree-sitter-12dpl.

print_usage() {
	printf 'vendor_parser.sh [-c <commit_hash>] <target_dir>

Arguments:
    target_dir          directory to save parser.c and parser.h files

Options:
    -c commit_hash      commit hash to download files from (defaults to the HEAD
                        of the main branch of the parser repository)
'
}

main() {
	commit_hash=''

	while getopts 'c:h' opt; do
		case "$opt" in
		'c')
			commit_hash=$OPTARG
			;;

		'h')
			print_usage
			exit 0
			;;

		*)
			print_usage
			exit 1
			;;
		esac
	done
	shift $((OPTIND - 1))

	if [ -z "$1" ]; then
		echo 'please provide target directory'
		print_usage
		exit 1
	fi
	if [ ! -d "$1" ]; then
		echo "target directory $1 does not exist"
		exit 1
	fi

	if [ -z "$commit_hash" ]; then
		if ! heads=$(git ls-remote -h --exit-code 'git@github.com:kelly-lin/tree-sitter-12dpl.git'); then
			echo 'could not get repository heads'
			exit 1
		fi
		commit_hash="$(echo "$heads" | grep 'refs/heads/main' | cut -f1)"
		if [ -z "$commit_hash" ]; then
			echo 'could not find main commit hash'
			exit 1
		fi
	fi

	if ! parser_c_content=$(curl -fs "https://raw.githubusercontent.com/kelly-lin/tree-sitter-12dpl/$commit_hash/src/parser.c"); then
		echo 'could not fetch parser.c'
		exit 1
	fi
	if ! parser_h_content=$(curl -fs "https://raw.githubusercontent.com/kelly-lin/tree-sitter-12dpl/$commit_hash/src/tree_sitter/parser.h"); then
		echo 'could not fetch parser.h'
		exit 1
	fi

	printf '// Vendored commit %s
%s' "$commit_hash" "$(printf "%s" "$parser_c_content" | sed 's|^#include <tree_sitter/parser.h>$|#include "parser.h"|')" >"$1/parser.c"

	printf '// Vendored commit %s
%s' "$commit_hash" "$parser_h_content" >"$1/parser.h"
}

main "$@"
