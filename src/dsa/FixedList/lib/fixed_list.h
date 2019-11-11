#ifndef FIXED_LIST_H
#define FIXED_LIST_H

#include <stdbool.h>

#define MAX_LENGTH_OF_FIXED_LIST 100

typedef int Fixed_List_ElementType;
typedef int Fixed_List_Position;
typedef struct FixedList {
    Fixed_List_ElementType Element[MAX_LENGTH_OF_FIXED_LIST];
    int length;
} FixedList;

bool is_empty_list(const FixedList);
Fixed_List_ElementType retrieve_from_list(const Fixed_List_Position,
                                          const FixedList);
void show_all_list(const FixedList);
void makenull_list(FixedList*);
void insert_to_list(const Fixed_List_ElementType, const Fixed_List_Position,
                    FixedList*);
void delete_from_list(const Fixed_List_Position, FixedList*);
Fixed_List_Position first_list(const FixedList);
Fixed_List_Position end_list(const FixedList);
Fixed_List_Position previous_position_of(const Fixed_List_Position,
                                         const FixedList);
Fixed_List_Position next_position_of(const Fixed_List_Position,
                                     const FixedList);
Fixed_List_Position locate_element_of_list(const Fixed_List_ElementType,
                                           const FixedList);

#endif
