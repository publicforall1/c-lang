#!/bin/bash

# Compile all files
echo "Compiling things..."
make prog=merge_sort
make prog=quick_sort

# Run internal tests
echo "Testing things..."
./merge_sort.out
./quick_sort.out

# Clean stuff
echo "Cleaning things..."
rm -rf *.out

echo "So fast, right?"
echo "It's a magic of algorithms."
