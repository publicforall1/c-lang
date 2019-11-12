#include "lib/binary_search_tree.h"
#include <stdio.h>

int main(void) {

    BS_Tree tree;
    makenull_bstree(&tree);

    insert_node_to_bstree(57, &tree);
    insert_node_to_bstree(68, &tree);
    insert_node_to_bstree(32, &tree);
    insert_node_to_bstree(18, &tree);
    insert_node_to_bstree(41, &tree);
    insert_node_to_bstree(60, &tree);
    insert_node_to_bstree(112, &tree);

    inorder_bstree(tree);
    printf("\n"); // 18 32 41 57 60 68 112
    delete_node_from_bstree(41, &tree);
    inorder_bstree(tree);
    printf("\n"); // 18 32 57 60 68 112
    delete_node_from_bstree(32, &tree);
    inorder_bstree(tree);
    printf("\n"); // 18 57 60 68 112
    delete_node_from_bstree(18, &tree);
    inorder_bstree(tree);
    printf("\n"); // 57 60 68 112
    delete_node_from_bstree(60, &tree);
    inorder_bstree(tree);
    printf("\n"); // 57 68 112
    delete_node_from_bstree(112, &tree);
    inorder_bstree(tree);
    printf("\n"); // 57 68

    destroy_bstree(tree);
    return 0;
}
