# -*- Makefile -*-
# Compile Instruction:
# 	make prog=[filename_without_extension]

CC = gcc
FLAGS = -std=c11 -fstack-protector -pedantic-errors -Wunused-variable -lm -Wall

${prog}.out: ${prog}.c
	@${CC} $< ${FLAGS} -o $@
