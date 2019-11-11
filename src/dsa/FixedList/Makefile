# -*- Makefile -*-
# Compile Instruction:
# 	make prog=[filename_without_extension]

${prog}: ${prog}.c lib/fixed_list.c
	gcc ${prog}.c lib/fixed_list.c \
	-std=c11 -fstack-protector -pedantic-errors -Wunused-variable -lm \
	-o ${prog}.out
