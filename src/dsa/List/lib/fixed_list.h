#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

#define MAX_LENGTH_OF_LIST 100

typedef int List_ElementType;
typedef int List_Position;
typedef struct List {
    List_ElementType element[MAX_LENGTH_OF_LIST];
    int length;
} List;

void init_list(List* l);                                        // O(1)
bool is_empty_list(List l);                                     // O(1)
List_Position first_list(List l);                               // O(1)
List_Position end_list(List l);                                 // O(1)
void insert_list(List_ElementType x, List_Position p, List* l); // O(n)
List_ElementType retrieve_list(List_Position p, List l);        // O(1)
void delete_list(List_Position p, List* l);                     // O(n)
List_Position prev_list(List_Position p, List l);               // O(1)
List_Position next_list(List_Position p, List l);               // O(1)
List_Position find_list(List_ElementType x, List l);            // O(n)
void print_list(List l);                                        // O(n)
void destroy_list(List l);                                      // O(1)

#endif
