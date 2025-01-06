#!/bin/bash

#rle.sh

# Encodes the elements of the array arr storing the result in the array enc

encode() {

    n=${#arr[@]}
    if [ $n -gt 0 ]; then
        start=0
        val=${arr[start]}
        finished=false
        while [ "$finished" = false ]; do
            end=$(next "$start")
            if [ "$end" = -1 ]; then
                end=$n
                finished=true
            fi
            count=$((end - start))
            enc+=("$count" "$val")
            start=$end
            val=${arr[start]}
        done
    fi
    
}

# Finds the index of the next element in arr that is different (not equal to) from the element located at the specified starting index; e.g., next 3
#
# Finds the index of the next element in arr that is not equal to the element at the starting index 3.
#
# The value of the found index is always greater than the specified index, or is -1 if all of the remaining elements in arr starting from the specified index are equal.
next() {
    start_index=$1
    for ((i = start_index + 1; i < ${#arr[@]}; i++)); do
        if [ "${arr[i]}" != "${arr[start_index]}" ]; then
            echo "$i"
            return
        fi
    done
    echo "-1"
}

# create array arr from command line arguments
arr=("$@")

# Initialize the encoded array
enc=()

# Encode array
encode

# Print elements of enc on one line with one space between all elements
echo "${enc[@]}"