#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdbool.h>

typedef char B_Tree_DataType;

struct B_Tree_Node {
    B_Tree_DataType value;
    struct B_Tree_Node* left;
    struct B_Tree_Node* right;
};

typedef struct B_Tree_Node* B_Tree;

void makenull_btree(B_Tree* root);
bool is_empty_btree(B_Tree root);
B_Tree merge_btree(B_Tree_DataType value, B_Tree first_tree,
                   B_Tree second_tree);
void destroy_btree(B_Tree root);
B_Tree_DataType get_value_from_btree(B_Tree node);
void preorder_btree(B_Tree root);
void inorder_btree(B_Tree root);
void postorder_btree(B_Tree root);

#endif
