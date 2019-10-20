#include "lib/binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){

    B_Tree tree;
    makenull_btree(&tree);
    
    // describe binary tree using merge_tree function
    // create leaf-nodes
    B_Tree D = merge_btree('D', NULL, NULL);
    B_Tree E = merge_btree('E', NULL, NULL);
    B_Tree F = merge_btree('F', NULL, NULL);
    B_Tree G = merge_btree('G', NULL, NULL);
    // connect 2 leaf-nodes to another node
    B_Tree B = merge_btree('B', D, E);
    B_Tree C = merge_btree('C', F, G);
    // connect 2 child with root-node
    tree = merge_btree('A', B, C); 

    preorder_btree(tree);

    destroy_btree(tree);
    return 0;
}

