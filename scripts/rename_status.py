import os
import sys
import re
import subprocess

# Is not able to find matches where the string is across new lines
INITIAL_MATCH_PATTERN = re.compile(r"StatusCode::k(\w+)")

MATCH_PATTERN = re.compile(
    r"Status[\(]\s*(google::cloud::)?\s*StatusCode::k(.*),\s*([\S\s]*)[\)];",
    re.MULTILINE,
)

REPLACE_PATTERN = r"internal::\2Error(\3, GCP_ERROR_INFO());"


def print_files_recursively(directory):
    """Prints all files within a directory and its subdirectories recursively.

    Args:
        directory: The path to the directory to start searching.
    """

    total_files = 0
    for root, _, files in os.walk(directory):
        for file in files:
            filename = os.path.join(root, file)
            # print(f"Trying file: {filename}")
            if filename.endswith("test.cc"):
                continue
            try:
                text = open(filename, "r").read()
            except:
                print("error")
                continue
            matches = re.findall(INITIAL_MATCH_PATTERN, text)
            if len(matches) == 0:
                continue
            if not all(x != "Unimplemented" and x != "Ok" for x in matches):
                continue
            # print(matches)
            total_files += 1
            print(f"Opening file: {filename}")
            print(f"Matches {len(matches)}: {matches}")

            # Replace the  match
            text = re.sub(MATCH_PATTERN, REPLACE_PATTERN, text, count=len(matches))

            # Find and add the include
            text = re.sub(
                re.compile(r"#include (.*)\n"),
                r'#include \1\n#include "google/cloud/internal/make_status.h"\n',
                text,
                count=1,
            )
            # if filename == "google/cloud/generator/internal/standalone_main.cc":
            # print(text)

            f = open(filename, "w")
            f.write("".join(text))
            f.close()

    print(f"Found matches in {total_files} files")


# Sample usage: python3 scripts/rename_status.py google/cloud/pubsub/internal
def main():
    # Get the directory path from command line arguments
    if len(sys.argv) > 1:
        directory = sys.argv[1]
    else:
        print("Error: Please provide a directory path as an argument.")
        exit(1)

    # Call the function to print the files
    print_files_recursively(directory)

    # subprocess.run(["ci/cloudbuild/build.sh", "-t", "checkers-pr"])


if __name__ == "__main__":
    main()
