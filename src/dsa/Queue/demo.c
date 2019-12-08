/**
 * Make sure Queue library works.
 * */

#include "lib/circular_queue.h"
#include <stdio.h>

Queue create_queue_and_makenull(){
    Queue q;
    makenull_queue(&q);
    return q;
}

Queue demo_enqueue(){
    Queue q = create_queue_and_makenull();
    enqueue(57, &q);
    enqueue(68, &q);
    print_queue(q); // 57, 68
    return q;
}

void demo_dequeue(){
    Queue q = demo_enqueue();
    dequeue(&q);
    print_queue(q); // 57
    dequeue(&q);
    print_queue(q); // empty queue
}

int main(void) {

    demo_enqueue();
    demo_dequeue();

    return 0;
}

