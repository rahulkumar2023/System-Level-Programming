#!/bin/bash

# Assign class name to fully_qualified_class_name
fully_qualified_class_name="$1"

# Assign everything prior to the last dot in the argument to package_name and everything after the last dot to class_name.
package_name="${fully_qualified_class_name%.*}"
class_name="${fully_qualified_class_name##*.}"

# Checks as to whether the package name is same or different from the class name
{ 
  [ "$package_name" != "$class_name" ] && echo "package $package_name;"
  [ "$package_name" != "$class_name" ] && echo

# Defines the class
  echo "public class $class_name {"
  echo "}"

# Redirects output to create Java file
} > "${class_name}.java"