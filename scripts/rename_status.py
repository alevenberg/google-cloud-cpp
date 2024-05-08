import os
import sys

def print_files_recursively(directory):
    """Prints all files within a directory and its subdirectories recursively.

    Args:
        directory: The path to the directory to start searching.
    """

    for root, _, files in os.walk(directory):
        for file in files:
            print(f"Opening file: {os.path.join(root, file)}")
            # f = open(file, "rw")
            # print(f)

# Sample usage: python3 rename_status.py ../google/cloud/pubsub/internal      
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