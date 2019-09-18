/**
 * - This program use to check if parentheses string is valid
 * - https://english.stackexchange.com/questions/3379/bracket-vs-brace
 *
 * ----Input----|----Output----
 *| "((()))"	|	true	|
 *| ")("	|	false	|
 *| "((())))"	|	false	|
 *| "((())"	|	false	|
 *
 * Function prototype: bool is_valid_parens_string(char* s);
 * */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "lib/stack.h"

bool is_valid_parens_string(char* s){
    int len = (int) strlen(s), i;
    if (len == 0)
	return false;

    Stack char_stack;
    makenull_stack(&char_stack);

    for(i = 0; i < len; ++i){
	if (s[i] == '('){
	    push(1, &char_stack);
	}else if (is_empty_stack(char_stack)){
	    return false;
	}else {
	    pop(&char_stack);
	}
    }

    return is_empty_stack(char_stack);
}

int main(void){
    

    printf("%d\n", is_valid_parens_string("((()))"));
    printf("%d\n", is_valid_parens_string(")("));
    printf("%d\n", is_valid_parens_string("((())))"));
    printf("%d\n", is_valid_parens_string("((())"));

    return 0;
}

