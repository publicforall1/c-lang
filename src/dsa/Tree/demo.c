#include "lib/tree.h"
#include <stdio.h>

#define PRINT_NEW_LINE printf("\n");

int main(void){
    
    Tree tree;
    makenull_tree(&tree);

    // Tree in diagram
    add_node('A', -1, &tree);
    add_node('B', 0, &tree);
    add_node('C', 0, &tree);
    add_node('D', 0, &tree);
    add_node('E', 1, &tree);
    add_node('F', 2, &tree);
    add_node('G', 2, &tree);
    add_node('H', 3, &tree);

    printf("Left-child of A: %c\n", get_value(left_child(0, tree), tree));
    printf("Left-child of B: %c\n", get_value(left_child(1, tree), tree));
    printf("Left-child of C: %c\n", get_value(left_child(2, tree), tree));
    printf("Left-child of D: %c\n", get_value(left_child(3, tree), tree));
    printf("Left-child of E: %c\n", get_value(left_child(4, tree), tree));
    printf("Left-child of F: %c\n", get_value(left_child(5, tree), tree));
    printf("Left-child of G: %c\n", get_value(left_child(6, tree), tree));
    printf("Left-child of H: %c\n", get_value(left_child(7, tree), tree));

    printf("Right-sibling of A: %d\n", right_sibling(0, tree));
    printf("Right-sibling of B: %d\n", right_sibling(1, tree));
    printf("Right-sibling of C: %d\n", right_sibling(2, tree));
    printf("Right-sibling of D: %d\n", right_sibling(3, tree));
    printf("Right-sibling of E: %d\n", right_sibling(4, tree));
    printf("Right-sibling of F: %d\n", right_sibling(5, tree));
    printf("Right-sibling of G: %d\n", right_sibling(6, tree));
    printf("Right-sibling of H: %d\n", right_sibling(7, tree));

    preorder(root_node(tree), tree); PRINT_NEW_LINE
    inorder(root_node(tree), tree); PRINT_NEW_LINE
    postorder(root_node(tree), tree); PRINT_NEW_LINE

    return 0;
}

