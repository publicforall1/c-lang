#include "lib/sll_compatible.h"
#include <stdio.h>

int main(void) {
    int n;
    SinglyLinkedList my_list;
    makenull_list(&my_list);

    printf("Enter number of elements: ");
    scanf("%d", &n);

    read_list(&my_list, n);

    show_all_list(my_list);

    destroy_list(my_list);

    return 0;
}
