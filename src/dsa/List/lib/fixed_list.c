#include "fixed_list.h"
#include <stdbool.h>
#include <stdio.h>

void init_list(List* l) { l->length = 0; } // O(1)

bool is_empty_list(List l) { return l.length == 0; } // O(1)

int first_list(List l) { return 1; } // O(1)

int end_list(List l) { return l.length + 1; } // O(1)

void insert_list(List_ElementType x, List_Position p, List* l) {
    // check is reached max length
    if (l->length == MAX_LENGTH_OF_LIST) {
        printf("insert list: list is full.\n");
        return;
    }

    // check is valid position
    if (p < 1 || p > l->length + 1) {
        printf("insert List: invalid position.\n");
        return;
    }

    // move all element start from p to the right side
    for (int i = end_list(*l) - 1; i > p - 1; --i) {
        l->element[i] = l->element[i - 1];
    }

    // put x to p position
    l->element[p - 1] = x;

    // increase length
    l->length++;
} // O(n)

List_ElementType retrieve_list(List_Position p, List l) {
    return l.element[p - 1];
} // O(1)

void delete_list(List_Position p, List* l) {
    // check is empty List
    if (is_empty_list(*l)) {
        printf("delete list: list is empty.\n");
        return;
    }

    // check is valid position
    if (p < 1 || p > l->length) {
        printf("delete list: invalid position.\n");
        return;
    }

    // start delete
    for (int i = p - 1; i < l->length - 1; i++) {
        l->element[i] = l->element[i + 1];
    }

    // decrease length
    l->length--;
}

List_Position prev_list(List_Position p, List l) { return p - 1; } // O(1)

List_Position next_list(List_Position p, List l) { return p + 1; } // O(1)

List_Position find_list(List_ElementType x, List l) {
    List_Position p = first_list(l);

    while (p != end_list(l)) {
        if (retrieve_list(p, l) == x) {
            break;
        }
        p = next_list(p, l);
    }
    return p;
} // O(n)

void print_list(List l) {
    List_Position p = first_list(l);
    printf("[ ");
    while (p != end_list(l)) {
        printf("%d ", retrieve_list(p, l));
        p = next_list(p, l);
    }
    printf("]\n");
} // O(n)

