# -*- Makefile -*-
# Compile Instruction:
# 	make prog=[filename_without_extension]

${prog}: ${prog}.c
	@gcc ${prog}.c lib/max_heap.c lib/min_heap.c lib/priority_queue.c \
	-std=c11 -fstack-protector -pedantic-errors -Wunused-variable -lm \
	-o ${prog}.out

clean:
	@rm *.out
