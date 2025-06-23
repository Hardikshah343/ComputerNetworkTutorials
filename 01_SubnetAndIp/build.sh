#!/bin/bash

# Name of the output binary
OUTPUT="subnet"

# Find all .c files in the current directory
SOURCES=$(find . -maxdepth 1 -name "*.c")

# Compiler and flags
CC="gcc"
CFLAGS="-Wall -Wextra -O2"

# Build command
echo "Compiling: $SOURCES"
$CC $CFLAGS $SOURCES -o $OUTPUT

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Build successful: ./$OUTPUT"
else
    echo "Build failed."
    exit 1
fi