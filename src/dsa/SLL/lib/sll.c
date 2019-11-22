/**
 * Singly-Linked Lists
 * @author: taiprogramer 
*/
#include "sll.h"
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

SinglyLinkedList_Position end_list(SinglyLinkedList header){
    if (header->next == NULL)
	return header;
    end_list(header->next);
}

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

SinglyLinkedList_ElementType list_value_at(SinglyLinkedList_Position P, SinglyLinkedList header){
    if (P->next != NULL)
	return P->next->val;
    return -111111;
}

void destroy_list(SinglyLinkedList header) {
    if (header->next != NULL)
        destroy_list(header->next);
    free(header);
}

void show_all_list(SinglyLinkedList header) {
    SinglyLinkedList_Position trav = header;
    printf("[ ");
    while (trav->next) {
        printf("%d ", list_value_at(trav, header));
        trav = trav->next;
    }
    printf("]\n");
}

