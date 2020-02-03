#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define MAX_LENGTH_OF_STACK 100

typedef int Stack_ElementType;
typedef struct {
    Stack_ElementType value[MAX_LENGTH_OF_STACK];
    int top_index;
} Stack;

void makenull_stack(Stack* stack);
bool is_empty_stack(Stack stack);
bool is_full_stack(Stack stack);
void push_stack(Stack_ElementType value, Stack* stack);
void pop_stack(Stack* stack);
Stack_ElementType top_stack(Stack stack);
void print_stack(Stack stack);

#endif
