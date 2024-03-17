#!/bin/sh
# Vendor in the parser files from https://github.com/kelly-lin/tree-sitter-12dpl.

print_usage() {
	printf 'vendor_parser.sh [-c <commit_hash>] <repo_ref> <branch_name> <target_dir>

Arguments:
    repo_ref            the github repository ref
                        the ref for "https://github.com/kelly-lin/tree-sitter-12dpl" is
                        "kelly-lin/tree-sitter-12dpl"
    branch_name         the branch to download parsers from
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

    repo_ref=$1
	if [ -z "$repo_ref" ]; then
		echo 'please provide repo ref'
		print_usage
		exit 1
	fi
    branch_name=$2
	if [ -z "$branch_name" ]; then
		echo 'please provide branch name'
		print_usage
		exit 1
	fi
    target_dir=$3
	if [ -z "$target_dir" ]; then
		echo 'please provide target directory'
		print_usage
		exit 1
	fi
	if [ ! -d "$target_dir" ]; then
		echo "target directory $target_dir does not exist"
		exit 1
	fi

	if [ -z "$commit_hash" ]; then
		if ! heads=$(git ls-remote -h --exit-code "https://github.com/$repo_ref"); then
			echo 'could not get repository heads'
			exit 1
		fi
		commit_hash="$(echo "$heads" | grep "refs/heads/$branch_name" | cut -f1)"
		if [ -z "$commit_hash" ]; then
			echo 'could not find main commit hash'
			exit 1
		fi
	fi

	if ! parser_c_content=$(curl -fs "https://raw.githubusercontent.com/$repo_ref/$commit_hash/src/parser.c"); then
		echo 'could not fetch parser.c'
		exit 1
	fi
	if ! parser_h_content=$(curl -fs "https://raw.githubusercontent.com/$repo_ref/$commit_hash/src/tree_sitter/parser.h"); then
		echo 'could not fetch parser.h'
		exit 1
	fi

	printf '// Vendored commit %s
%s' "$commit_hash" "$(printf "%s" "$parser_c_content" | sed 's|^#include <tree_sitter/parser.h>$|#include "parser.h"|')" >"$target_dir/parser.c"

	printf '// Vendored commit %s
%s' "$commit_hash" "$parser_h_content" >"$target_dir/parser.h"
}

main "$@"
