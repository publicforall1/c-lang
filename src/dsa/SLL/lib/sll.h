#ifndef SLL_H
#define SLL_H

#include <stdbool.h>

typedef int ElementType;

typedef struct sllist {
    ElementType val;
    struct sllist* next;
} sllnode;

sllnode* create(ElementType val);
bool is_exist(sllnode* head, ElementType lookup_value);
sllnode* insert(sllnode* head, ElementType val);
void destroy(sllnode* head);

#endif
