/**
 * - This program use to push value on the stack,
 *   & print it out. Very simple stuff.
 * - Purpose: Make sure stack library works fine.
 * */

#include "lib/stack.h"

#include <stdio.h>

int main(void){
    Stack my_stack;
    makenull_stack(&my_stack);

    int number_of_element = 10;
    for(int i = 0; i < number_of_element; ++i){
	push(i * 10,&my_stack); 
    }

    print_stack(my_stack);
    return 0;
}
