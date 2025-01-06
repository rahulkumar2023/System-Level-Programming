#!/bin/bash

# Initializes the variable result and sets it to 0.
result=0

# Loop iterates 8 times, generates a random bit of 0 or 1, and shifts the bit to the left each time.
for ((i = 0; i < 8; i++)); do
  bit=$((RANDOM % 2))
  result=$((result << 1 | bit))
done

# Prints the result
echo $result




