#ifndef SLL_COMPATIBLE_H
#define SLL_COMPATIBLE_H

#include <stdbool.h>

typedef int ElementType;

typedef struct sllist {
    ElementType val;
    struct sllist* next;
} sllnode;

typedef sllnode* Position;
typedef sllnode* List;

void makenull_list(List* header);
bool is_empty(List header);
Position locate(ElementType lookup_value, List header);
void insert_list(ElementType value, Position P, List* header);
void delete_list(Position P, List* header);
void destroy_list(List header);
void read_list(List* header, int number_of_element);
void show_all(List header);

#endif

