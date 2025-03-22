# Testing Directory
![Description of Image](https://i.pinimg.com/736x/fa/b6/dc/fab6dcc196253888778cf69c2a73a525.jpg)
## Overview
This directory contains test files for the custom `_printf` function. The purpose of these tests is to compare the output and behavior of `_printf` with the standard `printf` function to ensure correctness and consistency.

## Files
- **`main.c`**: A test file that executes multiple cases using `_printf` and compares the results with `printf`.
- **`printf_program`**: This file may contain compiled binaries or additional test-related content.

## Test Cases in `main.c`
The test file covers:
- Printing standard strings and characters.
- Handling integers (signed and unsigned).
- Printing octal, hexadecimal (lowercase & uppercase), and pointer addresses.
- Handling special cases such as percent signs (`%%`).
- Testing unknown format specifiers.

## Running Tests
To execute the tests, navigate to this directory and compile `main.c` along with `_printf` implementation using:

```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 ../*.c main.c -o test_printf
./test_printf
```

## Expected Output
The program should produce identical results for `_printf` and `printf`, except for unknown specifiers where `printf` will generate an error while `_printf` may handle it differently.

## Notes
- Ensure `_printf` is correctly implemented before running tests.
- Check for memory leaks using `valgrind` (Linux) or `asan` (Clang/GCC).
