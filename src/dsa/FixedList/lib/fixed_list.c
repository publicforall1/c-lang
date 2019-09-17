/**
 * @ Program:
 * - Implement List data structure based on array
 * - List of int number for easy to demonstrate
 *
 * @ List<ElementType>: is a collection of element with ElementType
 *
 * @ Marcos:
 * - capacity: capacity of list
 *
 * @ Properties:
 * - Element[capacity]: is an array of element with ElementType
 * - length: number of element in list
 *
 * @ Methods:
 * - makenull_list(L): create empty list
 * - is_empty_list(L): check is list empty
 * - first_list(L): return first position of list
 * - end_list(L): return position after last element
 * - insert_list(X, P, L): insert X element to P position of list L
 * - delete_list(P, L): delete element at P position
 * - previous(P, L): return position of P previous element
 * - next(P, L): return position of P next element
 * - retrieve(P, L): return value of element at P position
 * - locate(X, L): return position of X element
 * - show_all(L): display all element in list to screen
 *
 * @ Notes:
 * - Position of list count from 1 (very natural)
 * 
 * @ Styles:
 * - function: snake_case
 * - struct/custom datatype: CamelCase
 * - variable: snake_case
 * - param: [optional]
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include "fixed_list.h"

/* ============ Implement Func ============ */

/** makenull_list(L): create empty list
 * @ params: List* L - pointer of list (pass by reference)
 * @ return: (void)
 */
void makenull_list(List* L) { L->length = 0; }

/** is_empty_list(L): check is list empty
 * @ params: List L
 * @ return: (bool) 1 (true) if list is empty, otherwise 0 (false)
 */
bool is_empty_list(const List L) { return L.length == 0; }

/** first_list(L): return first position of list
 * @ params: List L
 * @ return: (int) first position of list
 */
int first_list(const List L) {
    /* position count from 1 so first position is 1 position */
    return 1;
}

/** end_list(L): return position after last element
 * @ params: List L
 * @ return: (int) position after last element
 *
 */
int end_list(const List L) { return L.length + 1; }

/** insert_list(X, P, L): insert X element to P position of list L
 * @ params:
 * - ElementType X: value need insert to list
 * - Position P: position - where to put new element
 * - List* L
 * @ return: (void)
 */
void insert_list(const ElementType X, const Position P, List* L) {
    /* check is reached max length */
    if (L->length == capacity) {
        printf("insert list: list is full.\n");
        return;
    }

    /* check is valid position */
    if (P < 1 || P > L->length + 1) {
        printf("insert list: invalid position.\n");
        return;
    }

    /* move all element start from P to the right side */
    for (int i = end_list(*L) - 1; i > P - 1; i--) {
        L->Element[i] = L->Element[i - 1];
    }

    /* put X to P position */
    L->Element[P - 1] = X;

    /* increase length */
    L->length++;
}

/** delete_list(P, L): delete element at P position
 * @ params:
 * - Position P: position - where want to delete
 * - List* L
 * @ return: (void)
 */
void delete_list(const Position P, List* L) {
    /* check is empty list */
    if (is_empty_list(*L)) {
        printf("delete list: list is empty.\n");
        return;
    }

    /* check is valid position */
    if (P < 1 || P > L->length) {
        printf("delete list: invalid position.\n");
        return;
    }

    /* start delete */
    for (int i = P - 1; i < L->length - 1; i++) {
        L->Element[i] = L->Element[i + 1];
    }

    /* decrease length */
    L->length--;
}

/** previous(P, L): return position of P previous element
 * @ params:
 * - Position P
 * - List L
 * @ return: (Position)
 */
Position previous(const Position P, const List L) { return P - 1; }

/** next(P, L): return position of P next element
 * @ params:
 * - Position P
 * - List L
 * @ return: (Position)
 */
Position next(const Position P, const List L) { return P + 1; }

/** retrieve(P, L): return value of element at P position
 * @ params:
 * - Position P
 * - List L
 * @ return: (ElementType)
 */
ElementType retrieve(const Position P, const List L) {
    return L.Element[P - 1];
}

/** locate(X, L): return position of X element
 * @ params:
 * - ElementType X
 * - List X
 * @ return: Position if found else return end_list position
 */
Position locate(const ElementType X, const List L) {
    Position p = first_list(L);

    while (p != end_list(L)) {
        if (retrieve(p, L) == X) {
            break;
        }
        p = next(p, L);
    }
    return p;
}

/** show_all(L): display all element in list to screen
 * @ params: List L
 * @ return: (void)
 */
void show_all(const List L) {
    Position p = first_list(L);
    printf("[ ");
    while (p != end_list(L)) {
        printf("%d ", retrieve(p, L));
        p = next(p, L);
    }
    printf("]\n");
}

void demo(void) {
    List L;
    /* MAKE NULL LIST */
    makenull_list(&L);

    /* INSERT NEW ELEMENT TO LIST */
    printf("============ INSERT ============\n");
    insert_list(5, 1, &L);
    insert_list(7, 2, &L);
    insert_list(6, 3, &L);
    insert_list(8, 4, &L);

    /* SHOW ALL */
    show_all(L);

    /* DELETE SOME ELEMENTS BASE ON VALUES */
    printf("============ DELETE ============\n");
    delete_list(locate(5, L), &L);
    delete_list(locate(8, L), &L);

    /* SHOW ALL */
    show_all(L);
}
