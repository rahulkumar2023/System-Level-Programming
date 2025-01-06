#!/bin/bash

#onq2java.sh

# Check if at least one argument is provided
if [ "$#" -eq 0 ]; then
  echo "At least one fully qualified class name is required" >&2
  exit 1
fi

# Function to create package directories and copy files
process_student_directory() {
  student_dir="$1"
  shift

  for class_name in "$@"; do 
  class_file="${class_name##*.}.java"
  if [ -f "$student_dir/$class_file" ]; then
   if [[ $class_name =~ [.] ]]; then
       cd "$student_dir"
       bash ../mkpkg.sh $class_name
       pkg=${class_name%.*}
       dir=${pkg//[.]//}
       cp "$class_file" "./$dir/$class_file"
       cd - > /dev/null
       
   fi
  fi 
  done
}

# Loop through student directories
for student_dir in */; do
# Remove trailing slash
  student_dir="${student_dir%/}" 
  if [ -d "$student_dir" ]; then
    process_student_directory "$student_dir" "$@"
  fi
done

