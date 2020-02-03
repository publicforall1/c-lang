# -*- Makefile -*-
# Compile Instruction:
# 	make prog=[filename_without_extension] type=[type_of_graph]

${prog}: ${prog}.o ${type}_graph.o stack.o queue.o list.o
	@gcc -o ${prog}.out \
	${prog}.o ${type}_graph.o stack.o queue.o list.o \
	-std=c11 -fstack-protector -pedantic-errors -Wunused-variable -lm \

${prog}.o: ${prog}.c
	@gcc -c ${prog}.c -o ${prog}.o

${type}_graph.o: lib/${type}_graph.c
	@gcc -c lib/${type}_graph.c -o ${type}_graph.o

stack.o: lib/stack/stack.c
	@gcc -c lib/stack/stack.c -o stack.o

queue.o: lib/queue/circular_queue.c
	@gcc -c lib/queue/circular_queue.c -o queue.o

list.o: lib/list/list.c
	@gcc -c lib/list/list.c -o list.o

clean:
	@rm *.o
