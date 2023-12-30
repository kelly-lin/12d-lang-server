#!/usr/bin/python3
# Applies the patches to the documentation.

import json
import argparse
import os
import sys


def patch_manual(patch_filepath, manual, manual_id_idx_map):
    """
    Patch the manual provided patch located at patch filepath. It will override
    the parsed manual properties.
    """
    if patch_filepath is not None:
        with open(patch_filepath) as patch_file:
            patch = json.load(patch_file)
            for patch in patch["patches"]:
                patch_id = patch["id"]
                if not patch_id in manual_id_idx_map:
                    exit("patch failed, manual item with id {} does not exist".format(
                        patch["id"]))
                manual_idx = manual_id_idx_map[patch_id]
                if "names" in patch:
                    manual["items"][manual_idx]["names"] = patch["names"]
                if "description" in patch:
                    manual["items"][manual_idx]["description"] = patch["description"]


def parse_args():
    parser = argparse.ArgumentParser(description="Patches the manual",)
    parser.add_argument("patch_filepath")
    parser.add_argument("manual_filepath", nargs="?",
                        help="filepath to manual, if not provided standard input will be used")
    args = parser.parse_args()

    if not os.path.isfile(args.patch_filepath):
        exit("patch file provided does not exist")
    if args.manual_filepath is not None and not os.path.isfile(args.manual_filepath):
        exit("manual file provided does not exist")

    return args.patch_filepath, args.manual_filepath


def main():
    patch_filepath, manual_filepath = parse_args()

    manual_file_reader = open(
        manual_filepath) if manual_filepath is not None else sys.stdin
    manual = json.load(manual_file_reader)
    manual_id_idx_map = {}
    for idx, manual_item in enumerate(manual["items"]):
        manual_id_idx_map[manual_item["id"]] = idx
    patch_manual(patch_filepath, manual, manual_id_idx_map)
    print(json.dumps(manual, indent=2))
    manual_file_reader.close()


if __name__ == "__main__":
    main()
