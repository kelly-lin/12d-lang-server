# Generates function call signature documentation from manual and prototype file.

import sys
import os
import re
import json


def print_usage():
    print("""Usage:
    gen_doc.py <prototype> <manual>

Description:
    Generates function call signature documentation from manual and prototype file.""")


class API:
    def __init__(self, name, description, id):
        self.name = name
        self.description = description
        self.id = id

    def __repr__(self) -> str:
        return "API({}, {}, {})".format(self.name, self.description, self.id)

    def toJSON(self):
        return self.__dict__


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
    return [re.sub(r"\s+", " ", name.replace(",", ", ")) for name in names]


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
            api = {"names": names, "description": description, "id": id}
            result[id] = api
            state = ""
            names = []
            description = ""
            continue

    return result


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

manual_file = open(manual_filepath, "r")
manual_lines = manual_file.readlines()

manual = parse_manual(manual_lines)

prototype_file = open(prototype_filepath, "r")
prototype_lines = prototype_file.readlines()


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


no_doc_warnings = []

for prototype_line in prototype_lines:
    id = get_id_proto(prototype_line)
    if id is None:
        no_doc_warnings.append("id not found for {}".format(prototype_line))
        continue

    if not id in manual:
        no_doc_warnings.append(prototype_line.strip())
        continue


def print_stderr(line):
    print(line, file=sys.stderr)


if len(no_doc_warnings) > 0:
    print_stderr("completed with {} warnings:".format(len(no_doc_warnings)))
    print_stderr("    documentation not found:")
    for warning in no_doc_warnings:
        print_stderr("        {}".format(warning))

print(json.dumps(manual))
