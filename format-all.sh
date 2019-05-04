#!/bin/bash
for f in ./Exercises/*.c
do
	clang-format -i $f
done

for f in ./Working/*.c
do
	clang-format -i $f
done