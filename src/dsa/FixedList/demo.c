#include "lib/fixed_list.h"
#include <stdio.h>

int main(void) {
    FixedList L;
    /* MAKE NULL LIST */
    makenull_list(&L);

    /* INSERT NEW ELEMENT TO LIST */
    printf("============ INSERT ============\n");
    insert_to_list(5, end_list(L), &L);
    insert_to_list(7, end_list(L), &L);
    insert_to_list(6, end_list(L), &L);
    insert_to_list(8, end_list(L), &L);

    /* SHOW ALL */
    show_all_list(L);

    /* DELETE SOME ELEMENTS BASE ON VALUES */
    printf("============ DELETE ============\n");
    delete_from_list(locate_element_of_list(5, L), &L);
    delete_from_list(locate_element_of_list(8, L), &L);

    /* SHOW ALL */
    show_all_list(L);
    return 0;
}
