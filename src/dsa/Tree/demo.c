#include "lib/tree.h"
#include <stdio.h>

#define PRINT_NEW_LINE printf("\n");

int main(void) {

    Tree tree;
    makenull_tree(&tree);

    // Tree in diagram
    add_node_to_tree('A', -1, &tree);
    add_node_to_tree('B', 0, &tree);
    add_node_to_tree('C', 0, &tree);
    add_node_to_tree('D', 0, &tree);
    add_node_to_tree('E', 1, &tree);
    add_node_to_tree('F', 2, &tree);
    add_node_to_tree('G', 2, &tree);
    add_node_to_tree('H', 3, &tree);

    printf("Left-child of A: %c\n",
           get_value_from_tree(tree_left_child_of(0, tree), tree));
    printf("Left-child of B: %c\n",
           get_value_from_tree(tree_left_child_of(1, tree), tree));
    printf("Left-child of C: %c\n",
           get_value_from_tree(tree_left_child_of(2, tree), tree));
    printf("Left-child of D: %c\n",
           get_value_from_tree(tree_left_child_of(3, tree), tree));
    printf("Left-child of E: %c\n",
           get_value_from_tree(tree_left_child_of(4, tree), tree));
    printf("Left-child of F: %c\n",
           get_value_from_tree(tree_left_child_of(5, tree), tree));
    printf("Left-child of G: %c\n",
           get_value_from_tree(tree_left_child_of(6, tree), tree));
    printf("Left-child of H: %c\n",
           get_value_from_tree(tree_left_child_of(7, tree), tree));

    printf("Right-sibling of A: %d\n", tree_right_sibling_of(0, tree));
    printf("Right-sibling of B: %d\n", tree_right_sibling_of(1, tree));
    printf("Right-sibling of C: %d\n", tree_right_sibling_of(2, tree));
    printf("Right-sibling of D: %d\n", tree_right_sibling_of(3, tree));
    printf("Right-sibling of E: %d\n", tree_right_sibling_of(4, tree));
    printf("Right-sibling of F: %d\n", tree_right_sibling_of(5, tree));
    printf("Right-sibling of G: %d\n", tree_right_sibling_of(6, tree));
    printf("Right-sibling of H: %d\n", tree_right_sibling_of(7, tree));

    preorder_tree(tree_root_node(tree), tree);
    PRINT_NEW_LINE
    inorder_tree(tree_root_node(tree), tree);
    PRINT_NEW_LINE
    postorder_tree(tree_root_node(tree), tree);
    PRINT_NEW_LINE

    return 0;
}
