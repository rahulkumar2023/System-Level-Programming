#!/bin/bash

# Gives error if arguments given by the user is not equal to 2
if [ $# != 2 ]; then
  echo "Usage: $0 file1 file2" >&2
  exit 1
fi

# Creates 2 arguments using the variables file1 and file2
file1="$1"
file2="$2"

# Get the current permissions of the files using stat
perm1_before=$(stat -c "%a" "$file1")
perm2_before=$(stat -c "%a" "$file2")

# Swap permissions
chmod "$perm2_before" "$file1"
chmod "$perm1_before" "$file2"

# Print the permissions before and after swapping
echo "$(stat -c "%A %a" "$file2") $file1"
echo "$(stat -c "%A %a" "$file1") $file2"

