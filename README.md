# System Level Programming Repository

This repository contains a collection of Bash scripts and C programs designed for various utility purposes, such as file manipulation, array processing, stack/list management, and more. The files are organized with clear naming conventions for ease of understanding and usage.

---

## Table of Contents

1. Bash Scripts
2. C Programs
3. How to Compile and Run C Programs
4. Contributors

---

## Bash Scripts

### 1. **commands_and_solutions.txt**
A text file containing detailed solutions for navigating directories and performing file operations in a simulated directory structure.

---

### 2. **commands_and_solutions_structure.zip**
A zip file containing the directory structure referenced in the `commands_and_solutions.txt` file.

---

### 3. **random_number_generator.sh**
Generates an 8-bit random number.  
**Usage:**  
```bash
./random_number_generator.sh
```

---

### 4. **random_bit_flip.sh**
Generates a single random bit (0 or 1).  
**Usage:**  
```bash
./random_bit_flip.sh
```

---

### 5. **reverse_and_cut_columns.sh**
Reverses the lines of a file, extracts a specified number of columns, restores the order, and adds line numbers.  
**Usage:**  
```bash
./reverse_and_cut_columns.sh <file_name> <num_columns>
```

---

### 6. **java_class_generator.sh**
Creates a Java class file with a specified package and class name.  
**Usage:**  
```bash
./java_class_generator.sh <fully_qualified_class_name>
```

---

### 7. **permission_swapper.sh**
Swaps the file permissions of two given files.  
**Usage:**  
```bash
./permission_swapper.sh <file1> <file2>
```

---

### 8. **submission_checker.sh**
Checks for the existence of files listed in a spec file and reports missing files.  
**Usage:**  
```bash
./submission_checker.sh <specfile>
```

---

### 9. **java_package_processor.sh**
Processes student directories, creates Java package directories, and organizes Java class files.  
**Usage:**  
```bash
./java_package_processor.sh <fully_qualified_class_names>
```

---

### 10. **run_length_encoder.sh**
Implements run-length encoding on an array of elements passed as arguments.  
**Usage:**  
```bash
./run_length_encoder.sh <array_elements>
```

---

### 11. **validate_phone_number.sh**
Validates whether the input is a valid 10-digit phone number.  
**Usage:**  
```bash
./validate_phone_number.sh <phone_number>
```

---

## C Programs

### 1. **integer_division_and_remainder.c**
Performs integer division, calculates the remainder, and computes the floating-point quotient.  
**Compilation:**  
```bash
gcc -o divide integer_division_and_remainder.c
./divide <int1> <int2>
```

---

### 2. **find_middle_value.c**
Determines the middle value of three given inputs.  
**Compilation:**  
```bash
gcc -o middle find_middle_value.c
./middle <val1> <val2> <val3>
```

---

### 3. **binary_sum_with_overflow_check.c**
Computes the sum of two 8-digit binary numbers using long addition and checks for overflow.  
**Compilation:**  
```bash
gcc -o binary_sum binary_sum_with_overflow_check.c
./binary_sum <binary1> <binary2>
```

---

### 4. **list_operations.c** and **list_operations.h**
Contains utility functions for list operations, such as inserting elements and splitting a list at a given index.

**Compilation:**
1. Ensure `list_operations.c` and `list_operations.h` are in the same directory, along with any dependencies like `list.c` and `list.h`.
2. Compile:
   ```bash
   gcc -c list_operations.c -o list_operations.o
   ```
3. If there's a `main.c` file using this library, link and build:
   ```bash
   gcc main.c list_operations.o list.c -o list_program
   ```

**Execution:**
```bash
./list_program
```

---

### 5. **stack_operations.c** and **stack_operations.h**
Provides utility functions for stack operations, such as splitting a stack and checking if it is sorted.

**Compilation:**
1. Ensure `stack_operations.c` and `stack_operations.h` are in the same directory, along with any dependencies like `stack.c` and `stack.h`.
2. Compile:
   ```bash
   gcc -c stack_operations.c -o stack_operations.o
   ```
3. If there's a `main.c` file using this library, link and build:
   ```bash
   gcc main.c stack_operations.o stack.c -o stack_program
   ```

**Execution:**
```bash
./stack_program
```

---

### 6. **array_processing_demo.c**
Demonstrates reading and decoding arrays from a file, handling input errors, and visualizing decoded data.  
**Compilation:**  
```bash
gcc -o arr_demo array_processing_demo.c
./arr_demo <file>
```

---

### 7. **array_operations.c**
Implements utility functions for reading, parsing, and decoding compressed arrays, including line handling and memory management.

---

## How to Compile and Run C Programs

1. Compile the individual files using the `gcc` command.
2. Link any required dependencies (e.g., header files and other C files).
3. Run the resulting executable with the appropriate arguments.

Example:
```bash
gcc -o program_name file1.c file2.c
./program_name [arguments]
```

---

## Contributors

- **Rahul Kumar** - Development and implementation.

---
