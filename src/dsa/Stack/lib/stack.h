#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define CAPACITY 6

typedef int ElementType;
typedef struct {
    ElementType value[CAPACITY];
    int top;
} Stack;

void makenull_stack(Stack* stack);
bool is_empty_stack(Stack stack);
bool is_full_stack(Stack stack);
void push(ElementType value, Stack* stack);
void pop(Stack* stack);
ElementType top(Stack stack);
void print_stack(Stack stack);

#endif
