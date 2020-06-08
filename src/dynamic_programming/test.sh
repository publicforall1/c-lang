#!/bin/bash

# [get all program files (.c files)]
for program_file in *.c
do
    program=`basename ${program_file} .c`
    echo -n "[$program]"
    make prog=$program
    ./$program.out
    rm -rf $program.out
    echo " -> success."
done

echo "[done]"
echo "> So fast, right?"
echo "> It's a magic of algorithms."
