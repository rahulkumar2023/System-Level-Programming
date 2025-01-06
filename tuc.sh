#!/bin/bash

# Takes 2 arguments from user and sets it to file and num_columns respectively.
file="$1"
num_columns="$2"

# Reverses the lines of the input file and extracts the no. of columns that the user asks for, which is also the second argument
rev "$file" |
  cut -f -$num_columns |

# Restores the original order of lines within the input file, adds a line number on each line, and separates the actual content from the line numbers using multiple spaces.
  rev |
  awk -v OFS='\t' '{print NR, $0}'