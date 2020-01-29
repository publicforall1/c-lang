#include "list.h"
#include <stdio.h>

void init_list(List* l) { l->length = 0; } // O(1)

void append(List* l, Type value) {
    l->arr[l->length] = value;
    l->length++;
} // O(1)

int is_exist(List l, Type value) {
    for (int i = 0; i < l.length; ++i) {
        if (value == l.arr[i]) {
            return 1;
        }
    }
    return 0;
} // O(n)

int length(List l) { return l.length; } // O(1)

Type value_at(List l, int position) { return l.arr[position - 1]; } // O(1)

void print_list(List l) {
    int len = length(l);
    printf("[ ");
    for (int i = 1; i <= len; ++i) {
        printf("%d ", value_at(l, i));
    }
    printf("]");
} // O(n)