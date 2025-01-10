//NAME: Cyrus Najmi-Vannini
//NETID: csn2

## Building Instructions:
To build the allocator, run:
```
make clean
make build
```

You can also make a tar file with `make tar`, if you'd like.

## Command-Line Arguments:
1. `412alloc -h`
   Displays a help message with valid command-line arguments.

2. `412alloc -x <filename>`
   Scans and parses the input block from filename, performs renaming on the code in the input block, and prints the results to stdout. Used for Code Check 1.

3. `412alloc k <filename>`
   - k: Number of registers to use (must be between 3-64)
   - filename: Path to ILOC input file
   Allocates registers for the ILOC code in the input file using k registers, and prints the allocated code to stdout.

Implementation Details:
- Uses bottom-up register allocation with spilling when necessary
- Handles rematerialization of loadI operations for better efficiency
- Preserves relative ordering of operations per lab requirements
- Works great and is really cool

File Structure:
- realloc.c - This is the guy that does the allocation.
- scanner.c - Does the parsing. It's Lab 1.
- Makefile - Build configuration