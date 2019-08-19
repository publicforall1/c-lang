/**
 * @ Program:
 * - Implement List data structure based on array
 * - List of int number for easy to demonstrate
 *
 * @ List<ElementType>: is a collection of element with ElementType
 *
 * @ Marcos:
 * - capacity: capacity of list
 * - ERROR_INVALID_POSITION: error message (when user function like insert,
 * delete)
 * - ERROR_THIS_LIST_IS_EMPTY: error message (function: delete)
 * - ERROR_LIST_IS_FULL: error message (function: insert)
 *
 * @ Properties:
 * - Element[capacity]: is an array of element with ElementType
 * - length: number of element in list
 *
 * @ Methods:
 * - MAKENULL_LIST(L): create empty list
 * - IS_EMPTY_LIST(L): check is list empty
 * - FIRST_LIST(L): return first position of list
 * - END_LIST(L): return position after last element
 * - INSERT_LIST(X, P, L): insert X element to P position of list L
 * - DELETE_LIST(P, L): delete element at P position
 * - PREVIOUS(P, L): return position of P previous element
 * - NEXT(P, L): return position of P next element
 * - RETRIEVE(P, L): return value of element at P position
 * - LOCATE(X, L): return position of X element
 * - SHOW_ALL(L): display all element in list to screen
 *
 * @ Notes:
 * - Position of list count from 1 (very natural)
 *
 */

#include <stdbool.h>
#include <stdio.h>

#define capacity 10
#define ERROR_INVALID_POSITION "Invalid position.\n"
#define ERROR_THIS_LIST_IS_EMPTY "This list is empty.\n"
#define ERROR_LIST_IS_FULL "List is full.\n"

typedef int ElementType;
typedef int Position;
typedef struct {
    ElementType Element[capacity];
    int length;
} List;

bool IS_EMPTY_LIST(const List);
ElementType RETRIEVE(const Position, const List);
void SHOW_ALL(const List);
void MAKENULL_LIST(List*);
void INSERT_LIST(const ElementType, const Position, List*);
void demo(void);
void DELETE_LIST(const Position, List*);
Position FIRST_LIST(const List);
Position END_LIST(const List);
Position PREVIOUS(const Position, const List);
Position NEXT(const Position, const List);
Position LOCATE(const ElementType, const List);

int main(void) {
    demo();
    return 0;
}

/* ============ Implement Func ============ */

/** MAKENULL_LIST(L): create empty list
 * @ params: List* L - pointer of list (pass by reference)
 * @ return: (void)
 */
void MAKENULL_LIST(List* L) { L->length = 0; }

/** IS_EMPTY_LIST(L): check is list empty
 * @ params: List L
 * @ return: (bool) 1 (true) if list is empty, otherwise 0 (false)
 */
bool IS_EMPTY_LIST(const List L) { return L.length == 0; }

/** FIRST_LIST(L): return first position of list
 * @ params: List L
 * @ return: (int) first position of list
 */
int FIRST_LIST(const List L) {
    /* position count from 1 so first position is 1 position */
    return 1;
}

/** END_LIST(L): return position after last element
 * @ params: List L
 * @ return: (int) position after last element
 *
 */
int END_LIST(const List L) { return L.length + 1; }

/** INSERT_LIST(X, P, L): insert X element to P position of list L
 * @ params:
 * - ElementType X: value need insert to list
 * - Position P: position - where to put new element
 * - List* L
 * @ return: (void)
 */
void INSERT_LIST(const ElementType X, const Position P, List* L) {
    /* check is reached max length */
    if (L->length == capacity) {
        printf(ERROR_LIST_IS_FULL);
        return;
    }

    /* check is valid position */
    if (P < 1 || P > L->length + 1) {
        printf(ERROR_INVALID_POSITION);
        return;
    }

    /* move all element start from P to the right side */
    for (int i = END_LIST(*L) - 1; i > P - 1; i--) {
        L->Element[i] = L->Element[i - 1];
    }

    /* put X to P position */
    L->Element[P - 1] = X;

    /* increase length */
    L->length++;
}

/** DELETE_LIST(P, L): delete element at P position
 * @ params:
 * - Position P: position - where want to delete
 * - List* L
 * @ return: (void)
 */
void DELETE_LIST(const Position P, List* L) {
    /* check is empty list */
    if (IS_EMPTY_LIST(*L)) {
        printf(ERROR_THIS_LIST_IS_EMPTY);
        return;
    }

    /* check is valid position */
    if (P < 1 || P > L->length) {
        printf(ERROR_INVALID_POSITION);
        return;
    }

    /* start delete */
    for (int i = P - 1; i < L->length - 1; i++) {
        L->Element[i] = L->Element[i + 1];
    }

    /* decrease length */
    L->length--;
}

/** PREVIOUS(P, L): return position of P previous element
 * @ params:
 * - Position P
 * - List L
 * @ return: (Position)
 */
Position PREVIOUS(const Position P, const List L) { return P - 1; }

/** NEXT(P, L): return position of P next element
 * @ params:
 * - Position P
 * - List L
 * @ return: (Position)
 */
Position NEXT(const Position P, const List L) { return P + 1; }

/** RETRIEVE(P, L): return value of element at P position
 * @ params:
 * - Position P
 * - List L
 * @ return: (ElementType)
 */
ElementType RETRIEVE(const Position P, const List L) {
    return L.Element[P - 1];
}

/** LOCATE(X, L): return position of X element
 * @ params:
 * - ElementType X
 * - List X
 * @ return: Position if found else return end_list position
 */
Position LOCATE(const ElementType X, const List L) {
    Position p = FIRST_LIST(L);

    while (p != END_LIST(L)) {
        if (RETRIEVE(p, L) == X) {
            break;
        }
        p = NEXT(p, L);
    }
    return p;
}

/** SHOW_ALL(L): display all element in list to screen
 * @ params: List L
 * @ return: (void)
 */
void SHOW_ALL(const List L) {
    Position p = FIRST_LIST(L);
    printf("[ ");
    while (p != END_LIST(L)) {
        printf("%d ", RETRIEVE(p, L));
        p = NEXT(p, L);
    }
    printf("]\n");
}

void demo(void) {
    List L;
    /* MAKE NULL LIST */
    MAKENULL_LIST(&L);

    /* INSERT NEW ELEMENT TO LIST */
    printf("============ INSERT ============\n");
    INSERT_LIST(5, 1, &L);
    INSERT_LIST(7, 2, &L);
    INSERT_LIST(6, 3, &L);
    INSERT_LIST(8, 4, &L);

    /* SHOW ALL */
    SHOW_ALL(L);

    /* DELETE SOME ELEMENTS BASE ON VALUES */
    printf("============ DELETE ============\n");
    DELETE_LIST(LOCATE(5, L), &L);
    DELETE_LIST(LOCATE(8, L), &L);

    /* SHOW ALL */
    SHOW_ALL(L);
}
