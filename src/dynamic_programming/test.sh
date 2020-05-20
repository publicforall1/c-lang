#!/bin/bash

# Programs list
programs=(Bellman_Ford_The_Shortest_Path)

# Compile all files
echo "> Compiling things..."
for program in "${programs[@]}"; do
    echo -e "\tCompile $program..."
    make prog=$program
done

# Run internal tests
echo "> Testing things..."
for program in "${programs[@]}"; do
    echo -e "\tExecuting $program..."
    ./$program.out
done

# Clean stuff
echo "> Cleaning things..."
rm -rf *.out

echo "> So fast, right?"
echo "> It's a magic of algorithms."
