/**
 * Make sure Queue library works.
 * */

#include "lib/queue.h"
#include <stdio.h>

int main(void) {
    Queue my_queue;
    makenull_queue(&my_queue);

    int total_element = 50;

    printf("\n============== Enqueue ==============\n");
    for (int i = 0; i < total_element; ++i) {
        enqueue(i * 2, &my_queue);
    }
    print_queue(my_queue);

    printf("\n============== Dequeue ==============\n");
    for (int i = 0; i < total_element; ++i) {
        dequeue(&my_queue);
    }
    print_queue(my_queue);

    return 0;
}
