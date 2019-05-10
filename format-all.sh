#!/bin/bash
for f in ./src/*/*.c
do
	echo Formatting $f
	clang-format -i $f
done