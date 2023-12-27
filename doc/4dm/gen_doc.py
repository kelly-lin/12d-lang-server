# Generates function call signature documentation from manual and prototype file.

import sys
import os
import re
import json


def print_usage():
    print("""Usage:
    gen_doc.py <prototype> <manual> [patch]

Description:
    Generates function call signature documentation from manual (text file) and
    prototype file (text file). The resulting documentation (json) will be
    patched with the provided patch file (json file)""")


def is_id_line(line):
    """
    Returns true when the line matches the ID descriptor inside the manual.
    """
    result = re.search(r"ID = \d+", line)

    return result is not None


def get_id_manual(line):
    result = re.search(r"ID = (\d+)", line)
    if result is None:
        return None

    return result.group(1)


def format_names(names):
    # correct spacing for commas
    result = [re.sub(r"\s+", " ", name.replace(",", ", ")) for name in names]
    # remove spaces in functions with no parameters
    result = [re.sub(r"\(\s+\)", "()", name) for name in result]

    return result


def parse_manual(lines):
    """
    Parses the manual lines into API objects.
    """
    result = {}
    state = None
    # name is an array to handle overloads
    names: list[str] = []
    description = ""
    id = ""
    # sometimes signatures span over multiple lines, when this flag is true, the
    # signature is complete
    for line in lines:
        if line == "Name\n":
            state = "Name"
            continue

        if state == "Name" and line != "Description\n":
            trimmed_line = line.replace("\n", "")
            if trimmed_line == "":
                continue

            names.append(trimmed_line)
            continue

        if line == "Description\n":
            state = "Description"
            continue

        if state == "Description" and not is_id_line(line):
            description = description + line

        if is_id_line(line):
            id = get_id_manual(line)
            if id is None:
                continue

            description = description.replace(
                "\n", "").replace(".", ". ").strip()

            joined_names = " ".join(names)
            names = []
            func_start_indexes = [match.start(0) for match in re.finditer(
                r"\w+ \w+\(", joined_names)]
            for start_idx in func_start_indexes:
                end_idx = joined_names.find(")", start_idx)
                names.append(joined_names[start_idx:end_idx+1])

            names = format_names(names)
            if len(names) > 0:
                result[id] = {
                    "names": names,
                    "description": description,
                    "id": id
                }

            state = ""
            names = []
            description = ""
            continue

    return result


def get_id_proto(line):
    """
    Gets the id from prototype file.
    """
    result = re.search(r"\/\/ ID = (\d+)", line)
    if result is None:
        return None

    return result.group(1)


def create_id_text(id):
    return "ID = {}".format(id)


def print_stderr(line):
    print(line, file=sys.stderr)


def transformManualToJsonFormat(manual):
    result = {"items": []}
    for id in manual:
        result["items"].append(manual[id])

    return result


def validate_args():
    args = sys.argv[1:]
    if len(args) == 0:
        print_usage()
        sys.exit(1)

    if args[0] == "-h":
        print_usage()
        sys.exit(0)

    prototype_filepath = args[0]
    if prototype_filepath is None:
        print("prototype filepath is required")
        print_usage()
        sys.exit(1)

    if not os.path.isfile(prototype_filepath):
        print("prototype file provided does not exist")
        print_usage()
        sys.exit(1)

    manual_filepath = args[1]
    if manual_filepath is None:
        print("manual filepath is required")
        print_usage()
        sys.exit(1)
    if not os.path.isfile(manual_filepath):
        print("manual file provided does not exist")
        print_usage()
        sys.exit(1)

    patch_filepath = None
    if len(args) > 2:
        patch_filepath = args[2]
        if patch_filepath is not None and not os.path.isfile(patch_filepath):
            print("patch file provided does not exist")
            print_usage()
            sys.exit(1)

    return prototype_filepath, manual_filepath, patch_filepath


def insert_missing_manual_items(prototype_lines, manual) -> list[str]:
    """
    Finds the prototypes defined in the prototype lines that do not exist in the
    manual and inserts them into the manual them with an empty manual item and
    returns a list of warnings.
    """
    no_doc_warnings = []
    for prototype_line in prototype_lines:
        id = get_id_proto(prototype_line)
        if id is None:
            no_doc_warnings.append(
                "id not found for {}".format(prototype_line))
            continue

        if not id in manual:
            # no_doc_warnings.append(prototype_line.strip())
            # Even though we did not successully parse the documentation from
            # the manual, we should still add in the function into the manual
            # so that we can manually add them by patching.
            match = re.search(r"(.*);.*\/\/ ID = \d+", prototype_line)
            if match is not None:
                name = match.group(1).strip()
                manual[id] = {
                    "names": [name],
                    "description": "",
                    "id": id
                }

    return no_doc_warnings


def print_warnings(no_doc_warnings):
    print_stderr("completed with {} warnings:".format(
        len(no_doc_warnings)))
    print_stderr("    documentation not found:")
    for warning in no_doc_warnings:
        print_stderr("        {}".format(warning))


def main():
    prototype_filepath, manual_filepath, patch_filepath = validate_args()

    manual_file = open(manual_filepath, "r")
    manual_lines = manual_file.readlines()
    manual = parse_manual(manual_lines)

    prototype_file = open(prototype_filepath, "r")
    prototype_lines = prototype_file.readlines()
    no_doc_warnings = insert_missing_manual_items(prototype_lines, manual)

    if patch_filepath is not None:
        with open(patch_filepath) as patch_file:
            patch = json.load(patch_file)
            for patch in patch["patches"]:
                patch_id = patch["id"]
                if not patch_id in manual:
                    print("patch failed, manual item with id {} does not exist".format(
                        patch["id"]))
                    exit(1)

                manual[patch_id]["names"] = patch["names"]
                manual[patch_id]["description"] = patch["description"]["new"]

    if len(no_doc_warnings) > 0:
        print_warnings(no_doc_warnings)

    print(json.dumps(transformManualToJsonFormat(manual), indent=2))


main()
