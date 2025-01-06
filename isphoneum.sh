#!/bin/bash

#isphoneum.sh

# Check if script has one command line argument
if [ "$#" -ne 1 ]; then
  echo "Usage: $0 <phone_number>"
  exit 1
fi

# Remove any hyphens and spaces from the phone number
phone_number=$(echo "$1" | tr -d ' -')

# Check if phone number consists of 10 digits.
if [[ $phone_number =~ ^[0-9]{10}$ ]]; then
  echo "1"
else
  echo "0"
fi
