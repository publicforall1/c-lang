/**
 * @ Program:
 * - Implement FixedList data structure based on array
 * - FixedList of int number for easy to demonstrate
 *
 * @ FixedList<Fixed_List_ElementType>: is a collection of element with
 * Fixed_List_ElementType
 *
 * @ Marcos:
 * - MAX_LENGTH_OF_FIXED_LIST: capacity of FixedList
 *
 * @ Properties:
 * - Element[MAX_LENGTH_OF_FIXED_LIST]: is an array of element with
 * Fixed_List_ElementType
 * - length: number of element in FixedList
 *
 * @ Methods:
 * - makenull_list: create empty FixedList
 * - is_empty_list: look at its name :D
 * - first_list: return first Fixed_List_Position of FixedList
 * - end_list: return Fixed_List_Position after last elementdelete_list
 * - insert_to_list: insert element FixedList
 * - delete_from_list: delete element at Fixed_List_Position
 * - previous_position_of: return Fixed_List_Position of P previous element
 * - next_position_of: return Fixed_List_Position of P next element
 * - retrieve_from_list: return value of element at P Fixed_List_Position
 * - locate_element_of_list: return Fixed_List_Position of X element
 * - show_all_list: display all element in FixedList to screen
 *
 * @ Notes:
 * - Fixed_List_Position of FixedList count from 1 (very natural)
 *
 * @ Styles:
 * - function: snake_case
 * - struct/custom datatype: CamelCase
 * - variable: snake_case
 * - param: [optional]
 *
 */

#include "fixed_list.h"
#include <stdbool.h>
#include <stdio.h>

void makenull_list(FixedList* L) { L->length = 0; }

bool is_empty_list(const FixedList L) { return L.length == 0; }

int first_list(const FixedList L) {
    /* Fixed_List_Position count from 1 so first Fixed_List_Position is 1
     * Fixed_List_Position */
    return 1;
}

int end_list(const FixedList L) { return L.length + 1; }

void insert_to_list(const Fixed_List_ElementType X, const Fixed_List_Position P,
                    FixedList* L) {
    /* check is reached max length */
    if (L->length == MAX_LENGTH_OF_FIXED_LIST) {
        printf("insert FixedList: FixedList is full.\n");
        return;
    }

    /* check is valid Fixed_List_Position */
    if (P < 1 || P > L->length + 1) {
        printf("insert FixedList: invalid Fixed_List_Position.\n");
        return;
    }

    /* move all element start from P to the right side */
    for (int i = end_list(*L) - 1; i > P - 1; i--) {
        L->Element[i] = L->Element[i - 1];
    }

    /* put X to P Fixed_List_Position */
    L->Element[P - 1] = X;

    /* increase length */
    L->length++;
}

void delete_from_list(const Fixed_List_Position P, FixedList* L) {
    /* check is empty FixedList */
    if (is_empty_list(*L)) {
        printf("delete FixedList: FixedList is empty.\n");
        return;
    }

    /* check is valid Fixed_List_Position */
    if (P < 1 || P > L->length) {
        printf("delete FixedList: invalid Fixed_List_Position.\n");
        return;
    }

    /* start delete */
    for (int i = P - 1; i < L->length - 1; i++) {
        L->Element[i] = L->Element[i + 1];
    }

    /* decrease length */
    L->length--;
}

Fixed_List_Position previous_position_of(const Fixed_List_Position P,
                                         const FixedList L) {
    return P - 1;
}

Fixed_List_Position next_position_of(const Fixed_List_Position P,
                                     const FixedList L) {
    return P + 1;
}

Fixed_List_ElementType retrieve_from_list(const Fixed_List_Position P,
                                          const FixedList L) {
    return L.Element[P - 1];
}

Fixed_List_Position locate_element_of_list(const Fixed_List_ElementType X,
                                           const FixedList L) {
    Fixed_List_Position p = first_list(L);

    while (p != end_list(L)) {
        if (retrieve_from_list(p, L) == X) {
            break;
        }
        p = next_position_of(p, L);
    }
    return p;
}

void show_all_list(const FixedList L) {
    Fixed_List_Position p = first_list(L);
    printf("[ ");
    while (p != end_list(L)) {
        printf("%d ", retrieve_from_list(p, L));
        p = next_position_of(p, L);
    }
    printf("]\n");
}
