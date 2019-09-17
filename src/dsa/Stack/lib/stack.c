/**
 * Stack: Last In First Out (LIFO)
 * - save on stack memory in RAM (static allocation)
 * */

#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

void makenull_stack(Stack* stack){
    stack->top = CAPACITY;
}

bool is_empty_stack(Stack stack){
    return stack.top == CAPACITY;
}

bool is_full_stack(Stack stack){
    return stack.top == 0;
}

void push(ElementType value, Stack* stack){
    if (is_full_stack(*stack)){
	printf("push: stack is full.\n");
	return;
    }

    stack->top--;
    stack->value[stack->top] = value;
}

void pop(Stack* stack){
    if (is_empty_stack(*stack)){
	printf("pop: stack is empty.\n");
	return;
    }

    stack->top++;
}

ElementType top(Stack stack){
    return stack.value[stack.top];
}

void print_stack(Stack stack){
    Stack copied_stack = stack;
    printf("[ ");
    while(!is_empty_stack(copied_stack)){
	printf("%d ", top(copied_stack));
	pop(&copied_stack);
    }
    printf("]");
}
