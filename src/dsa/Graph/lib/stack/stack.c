/**
 * Stack: Last In First Out (LIFO)
 * - save on stack memory in RAM (static allocation)
 * */

#include "stack.h"
#include <stdbool.h>
#include <stdio.h>

void makenull_stack(Stack* stack) { stack->top_index = MAX_LENGTH_OF_STACK; }

bool is_empty_stack(Stack stack) {
    return stack.top_index == MAX_LENGTH_OF_STACK;
}

bool is_full_stack(Stack stack) { return stack.top_index == 0; }

void push_stack(Stack_ElementType value, Stack* stack) {
    if (is_full_stack(*stack)) {
        printf("push_stack: stack is full.\n");
        return;
    }

    stack->top_index--;
    stack->value[stack->top_index] = value;
}

void pop_stack(Stack* stack) {
    if (is_empty_stack(*stack)) {
        printf("pop_stack: stack is empty.\n");
        return;
    }

    stack->top_index++;
}

Stack_ElementType top_stack(Stack stack) {
    return stack.value[stack.top_index];
}

void print_stack(Stack stack) {
    printf("[ ");
    while (!is_empty_stack(stack)) {
        printf("%d ", top_stack(stack));
        pop_stack(&stack);
    }
    printf("]");
}
