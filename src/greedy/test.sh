#!/bin/bash

# Programs list
programs=(Kruskal_minimum_spanning_tree fractional_knapsack)

# Compile all files
echo "> Compiling things..."
for program in "${programs[@]}"; do
    echo "Compile $program..."
    make prog=$program
done

# Run internal tests
echo "> Testing things..."
for program in "${programs[@]}"; do
    echo "Executing $program..."
    ./$program.out
done

# Clean stuff
echo "> Cleaning things..."
rm -rf *.out

echo "> So fast, right?"
echo "> It's a magic of algorithms."
