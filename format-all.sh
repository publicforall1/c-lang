#!/bin/bash
# @deprecated: we are not using it anymore.

for f in ./src/*/*.c
do
	echo Formatting $f
	clang-format -i $f
done
