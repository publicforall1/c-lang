/**
 * Singly-Linked Lists (Compatible)
 * @ Meta: add more abstraction (high level, generalized)
 * @ Support functions:
 * - makenull_list: create empty list (1 block = header of list)
 * - is_empty_list: look at its name :D
 * - first_list: return first position (address) of list
 * - locate_element_of_list: find position of element (address)
 * - insert_to_list: insert element to list
 * - delete_from_list: delete element from list
 * - destroy_list: delete entire list, include free memory
 * - read_list: read input & add to list
 * - show_all_list: show all elements of list
 *
 */

#include "sll_compatible.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void makenull_list(SinglyLinkedList* header) {
    sllnode* node = (sllnode*)malloc(sizeof(sllnode));
    if (!node) {
        printf(
            "makenull_list: out of memory, assign NULL to header of list.\n");
        *header = NULL;
    }
    node->next = NULL;
    *header = node;
}

bool is_empty_list(SinglyLinkedList header) { return header->next == NULL; }

SinglyLinkedList_Position first_list(SinglyLinkedList header) { return header; }

SinglyLinkedList_Position
locate_element_of_list(SinglyLinkedList_ElementType lookup_value,
                       SinglyLinkedList header) {
    /**
     * @return SinglyLinkedList_Position (address) of previous block if found,
     * // ++
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

void insert_to_list(SinglyLinkedList_ElementType value,
                    SinglyLinkedList_Position P, SinglyLinkedList* header) {
    sllnode* node = (sllnode*)malloc(sizeof(sllnode));
    if (!node) {
        printf("insert_to_list: out of memory, do nothing.\n");
        return;
    }

    node->val = value;
    node->next = P->next;
    P->next = node;
}

void delete_from_list(SinglyLinkedList_Position P, SinglyLinkedList* header) {
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

void destroy_list(SinglyLinkedList header) {
    if (header->next != NULL)
        destroy_list(header->next);
    free(header);
}

void read_list(SinglyLinkedList* header, int number_of_element) {
    int i = -1, input_value;
    while (++i < number_of_element) {
        printf("Enter value #%d: ", i + 1);
        scanf("%d", &input_value);
        insert_to_list(input_value, first_list(*header), header);
    }
}

void show_all_list(SinglyLinkedList header) {
    sllnode* trav = header->next;
    printf("[ ");
    while (trav) {
        printf("%d ", trav->val);
        trav = trav->next;
    }
    printf("]\n");
}
