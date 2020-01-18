#include "list.h"

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