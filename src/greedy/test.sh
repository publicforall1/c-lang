#!/bin/bash

# Compile all files
echo "Compiling things..."
make prog=Kruskal_minimum_spanning_tree

# Run internal tests
echo "Testing things..."
./Kruskal_minimum_spanning_tree.out

# Clean stuff
echo "Cleaning things..."
rm -rf *.out

echo "So fast, right?"
echo "It's a magic of algorithms."
