import os
import sys
import re

# Is not able to find matches where the string is across new lines
MATCH_PATTERN = re.compile(r"Status\(StatusCode::k(.*),\s*\"(.*)\"\)")
REPLACE_PATTERN = r'internal::\1Error("\2", GCP_ERROR_INFO())'


def print_files_recursively(directory):
    """Prints all files within a directory and its subdirectories recursively.

    Args:
        directory: The path to the directory to start searching.
    """

    total_files = 0
    for root, _, files in os.walk(directory):
        for file in files:
            filename = os.path.join(root, file)
            if filename.endswith("test.cc"):
                continue
            if filename.endswith("connection.cc"):
                continue
            try:
                text = open(filename, "r").read()
            except:
                print("error")
                continue
            matches = re.findall(MATCH_PATTERN, text)
            if len(matches) == 0:
                continue
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
            # if filename == "google/cloud/pubsub/internal/rejects_with_ordering_key.cc":
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


if __name__ == "__main__":
    main()
