#ifndef SLL_COMPATIBLE_H
#define SLL_COMPATIBLE_H

#include <stdbool.h>

typedef int SinglyLinkedList_ElementType;

typedef struct sllist {
    SinglyLinkedList_ElementType val;
    struct sllist* next;
} sllnode;

typedef sllnode* SinglyLinkedList_Position;
typedef sllnode* SinglyLinkedList;

void makenull_list(SinglyLinkedList* header);
bool is_empty_list(SinglyLinkedList header);
SinglyLinkedList_Position first_list(SinglyLinkedList header);
SinglyLinkedList_Position
locate_element_of_list(SinglyLinkedList_ElementType lookup_value,
                       SinglyLinkedList header);
void insert_to_list(SinglyLinkedList_ElementType value,
                    SinglyLinkedList_Position P, SinglyLinkedList* header);
void delete_from_list(SinglyLinkedList_Position P, SinglyLinkedList* header);
void destroy_list(SinglyLinkedList header);
void read_list(SinglyLinkedList* header, int number_of_element);
void show_all_list(SinglyLinkedList header);

#endif
