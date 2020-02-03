# -*- Makefile -*-
# Compile Instruction:
# 	make prog=[filename_without_extension] type=[type_of_graph]

${prog}: ${prog}.c lib/${type}_graph.c lib/list/list.c lib/stack/stack.c
	@gcc ${prog}.c lib/${type}_graph.c  lib/list/list.c lib/stack/stack.c \
	-std=c11 -fstack-protector -pedantic-errors -Wunused-variable -lm \
	-o ${prog}.out
