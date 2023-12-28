#!/usr/bin/python3

import argparse
import os
import subprocess
import json


def get_head_manual(filepath):
    """
    Get the version of the manual from the HEAD of the branch.
    """
    get_head_version_args = ["git", "show", "main:{}".format(filepath)]
    proc = subprocess.run(get_head_version_args, stdout=subprocess.PIPE)
    if not proc.returncode == 0:
        exit("failed to execute: {}".format(get_head_version_args))
    return json.loads(proc.stdout)


def main():
    parser = argparse.ArgumentParser(
        description="create a patch from a modified manual file")
    parser.add_argument("filepath", help="generated manual filepath")
    parser.add_argument(
        "patch_filepath", help="filepath to patch file, will be created if it does not exist")
    args = parser.parse_args()

    if not os.path.isfile(args.filepath):
        exit("file {} does not exist".format(args.filepath))

    head_manual = get_head_manual(args.filepath)

    patch_obj = {"patches": []}
    if os.path.isfile(args.patch_filepath):
        with open(args.patch_filepath) as f:
            patch_obj = json.load(f)

    patch_lookup = {}
    for idx, patch in enumerate(patch_obj["patches"]):
        patch_lookup[patch["id"]] = idx

    with open(args.filepath) as modified_file:
        modified_manual = json.load(modified_file)
        for idx, head_manual_item in enumerate(head_manual["items"]):
            modified_manual_item = modified_manual["items"][idx]
            if head_manual_item["id"] != modified_manual_item["id"]:
                exit("expected id's at index {} to be equal but was not: head item id {} modified manual id {}".format(
                    idx, head_manual_item["id"], modified_manual["items"][idx]["id"]))
            result = None
            if head_manual_item != modified_manual_item:
                result = modified_manual_item
            if result is None:
                continue
            if result["id"] in patch_lookup:
                patch_idx = patch_lookup[result["id"]]
                patch_obj["patches"][patch_idx] = result
            else:
                patch_obj["patches"].append(result)

    with open(args.patch_filepath, "w") as patch_file:
        patch_file.write(json.dumps(patch_obj, indent=2))


if __name__ == "__main__":
    main()
