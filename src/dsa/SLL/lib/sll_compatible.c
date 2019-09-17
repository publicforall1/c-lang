/**
 * Singly-Linked Lists (Compatible)
 * @ Meta: add more abstraction (high level, generalized)
 * @ Support functions:
 * - makenull_list: create empty list (1 block = header of list)
 * - is_empty_list: look at its name :D
 * - locate: find position of element (address)
 * - insert_list: insert element to list
 * - delete_list: delete element from list
 * - destroy_list: delete entire list, include free memory
 * - read_list: read input & add to list
 * - show_all: show all elements of list
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "sll_compatible.h"

void makenull_list(List* header) {
    sllnode* node = (sllnode*)malloc(sizeof(sllnode));
    if (!node) {
        printf(
            "makenull_list: out of memory, assign NULL to header of list.\n");
        *header = NULL;
    }
    node->next = NULL;
    *header = node;
}

bool is_empty(List header) {
    return header->next == NULL;
}

Position locate(ElementType lookup_value, List header) {
    /**
     * @return Position (address) of previous block if found, // ++
     * // ++ else return NULL;
     */

    sllnode* previous_block = header;
    sllnode* trav = header->next;

    while (trav) {
        if (trav->val == lookup_value)
            return previous_block;
        previous_block = trav;
        trav = trav->next;
    }
    return NULL;
}

void insert_list(ElementType value, Position P, List* header) {
    sllnode* node = (sllnode*)malloc(sizeof(sllnode));
    if (!node) {
        printf("insert_list: out of memory, do nothing.\n");
        return;
    }

    node->val = value;
    node->next = P->next;
    P->next = node;
}

void delete_list(Position P, List* header) {
    /**
     * @description: delete next block of P position
     *
     */
    sllnode* next_block = P->next;
    if (!next_block)
        return;
    P->next = next_block->next;
    free(next_block);
}

void destroy_list(List header) {
    if (header->next != NULL)
        destroy_list(header->next);
    free(header);
}

void read_list(List* header, int number_of_element) {
    makenull_list(header);
    int i = 0, input_value;
    while (i < number_of_element) {
        printf("Enter value #%d: ", i + 1);
        scanf("%d", &input_value);
        fflush(stdin);
        insert_list(input_value, *header, header);
        ++i;
    }
}

void show_all(List header) {
    sllnode* trav = header->next;
    printf("[ ");
    while (trav) {
        printf("%d ", trav->val);
        trav = trav->next;
    }
    printf("]\n");
}

