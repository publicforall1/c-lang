# -*- Makefile -*-
# Compile Instruction:
# 	make prog=[filename_without_extension] type=[type_of_graph]

${prog}: ${prog}.c lib/${type}_graph.c
	gcc ${prog}.c lib/${type}_graph.c \
	-std=c11 -fstack-protector -pedantic-errors -Wunused-variable -lm \
	-o ${prog}.out

