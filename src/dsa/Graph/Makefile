# -*- Makefile -*-
# Compile Instruction:
# 	make prog=[filename_without_extension]

${prog}: ${prog}.c
	gcc ${prog}.c lib/vertices_edges_graph.c \
	-std=c11 -fstack-protector -pedantic-errors -Wunused-variable -lm \
	-o ${prog}.out

