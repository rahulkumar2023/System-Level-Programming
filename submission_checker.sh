#!/bin/bash

#checksub.sh

# Check if correct number of arguments is provided
if [ "$#" -ne 1 ]; then
  echo "Usage: $0 specfile" >&2
  exit 1
fi

specfile="$1"

# Check if specfile exists and is readable
if [ ! -r "$specfile" ]; then
  echo "$specfile is missing or could not be read" >&2
  exit 2
fi

# Initialize exit status
exit_status=0

# Process each line within the specfile
while read -r line; do
  # Remove the leading and trailing whitespace
  line=$(echo "$line" | sed -e 's/^[[:space:]]*//' -e 's/[[:space:]]*$//')

  # Skip the empty lines and comments (lines starting with #)
  if [ -n "$line" ] && [ "${line:0:1}" != "#" ]; then
    # Check if the file exists within the current directory
    if [ ! -f "$line" ]; then
      echo "$line missing" >&2
      exit_status=3
    fi
  fi
done < "$specfile"

exit "$exit_status"
