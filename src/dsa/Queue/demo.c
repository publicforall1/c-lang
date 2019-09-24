/**
 * Make sure Queue library works.
 * */

#include "lib/queue.h"
#include <stdio.h>

int main(void){
    Queue my_queue;
    makenull_queue(&my_queue);

    int total_element = 50;
    for(int i = 0; i < total_element; ++i){
	printf("Enqueue #%d\n", i);
	enqueue(i * 2, &my_queue); 
    }

    for(int i = 0; i < total_element; ++i){
	printf("Dequeue #%d\n", i);
	dequeue(&my_queue);
    }
    print_queue(my_queue);

    return 0;
}

