#!/bin/bash

echo '# Compiling...'
make prog=demo

echo '# Testing...'
./demo.out

echo '# Cleaning...'
make clean

echo '# Done.'
