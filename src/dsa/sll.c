/**
 * Singly Linked List
 * @ Support functions:
 * - create: create list if it's not exist
 * - is_exist: check if element is exist
 * - insert: insert item to list
 * - destroy: delete entire list, free memory
 * @ Full explanation
 * - CS50 Singly-Linked Lists [Youtube Video]
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct sllist {
    ElementType val;
    struct sllist* next;
} sllnode;

sllnode* create(ElementType val) {
    /**
     * @return pointer to sllnode or NULL pointer if out of memory.
     *
     */
    sllnode* node = (sllnode*)malloc(sizeof(sllnode));
    if (!node) {
        printf("create: out of memory, return NULL.\n");
        return NULL;
    }
    node->val = val;
    node->next = NULL;

    return node;
}

bool is_exist(sllnode* head, ElementType lookup_value) {
    /**
     * @return true if lookup_value is exist, else return false
     *
     */
    sllnode* trav = head;

    while (trav != NULL) {
        if (trav->val == lookup_value)
            return true;
        trav = trav->next;
    }
    return false;
}

sllnode* insert(sllnode* head, ElementType val) {
    sllnode* node = (sllnode*)malloc(sizeof(sllnode));

    if (!node) {
        printf("insert: out of memory, return 'head' pointer.\n");
        return head;
    }

    node->val = val;
    node->next = head;
    return node;
}

void destroy(sllnode* head) {
    /* @description: delete entire list, include free memory */
    if (head->next != NULL)
        destroy(head->next);
    free(head);
}

int main(void) { return 0; }