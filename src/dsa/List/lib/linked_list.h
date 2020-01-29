#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef int List_ElementType;

typedef struct sllist {
    List_ElementType val;
    struct sllist* next;
} sllnode;

typedef sllnode* List_Position;
typedef sllnode* List;

void init_list(List* l);                                        // O(1)
bool is_empty_list(List l);                                     // O(1)
List_Position first_list(List l);                               // O(1)
List_Position end_list(List l);                                 // O(n)
void insert_list(List_ElementType x, List_Position p, List* l); // O(1)
List_ElementType retrieve_list(List_Position p, List l);        // O(1)
void delete_list(List_Position p, List* l);                     // O(1)
List_Position prev_list(List_Position p, List l);               // O(1)
List_Position next_list(List_Position p, List l);               // O(1)
List_Position find_list(List_ElementType x, List l);            // O(n)
void print_list(List l);                                        // O(n)
void destroy_list(List l);                                      // O(n)

#endif
