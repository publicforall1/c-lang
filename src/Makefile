# -*- Makefile -*-
# Compile Instruction:
# 	make prog=[filename_without_extension]

${prog}: ${prog}.c
	gcc ${prog}.c \
	-std=c90 -fstack-protector -pedantic-errors -Wunused-variable -lm \
	-o ${prog}