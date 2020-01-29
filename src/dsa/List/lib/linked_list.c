/**
 * Singly-Linked Lists
 * @author: taiprogramer
 */
#include "linked_list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void init_list(List* l) {
    sllnode* node = (sllnode*)malloc(sizeof(sllnode));
    if (!node) {
        printf("init_list: out of memory, assign NULL to l of list.\n");
        *l = NULL;
        return;
    }
    node->next = NULL;
    *l = node;
}

bool is_empty_list(List l) { return l->next == NULL; }

List_Position first_list(List l) { return l; }

List_Position end_list(List l) {
    if (l->next == NULL)
        return l;
    return end_list(l->next);
}

void insert_list(List_ElementType value, List_Position p, List* l) {
    sllnode* node = (sllnode*)malloc(sizeof(sllnode));
    if (!node) {
        printf("insert_list: out of memory, do nothing.\n");
        return;
    }

    node->val = value;
    node->next = p->next;
    p->next = node;
}

List_ElementType retreive_list(List_Position p, List l) {
    if (p->next != NULL)
        return p->next->val;
    return -111111;
}

void delete_list(List_Position p, List* l) {
    /**
     * @description: delete next block of p position
     *
     */
    sllnode* next_block = p->next;
    if (!next_block)
        return;
    p->next = next_block->next;
    free(next_block);
}

List_Position prev_list(List_Position p, List l) {
    // Not implement yet
} // O(n)

List_Position next_list(List_Position p, List l) { return p->next; } // O(1)

List_Position find_list(List_ElementType lookup_value, List l) {
    /**
     * @return List_Position (address) of previous block if found,
     * // ++
     * // ++ else return NULL;
     */

    sllnode* previous_block = l;
    sllnode* trav = l->next;

    while (trav) {
        if (trav->val == lookup_value)
            return previous_block;
        previous_block = trav;
        trav = trav->next;
    }
    return NULL;
}

void print_list(List l) {
    List_Position trav = l;
    printf("[ ");
    while (trav->next) {
        printf("%d ", retreive_list(trav, l));
        trav = trav->next;
    }
    printf("]\n");
}

void destroy_list(List l) {
    if (l->next != NULL)
        destroy_list(l->next);
    free(l);
}
