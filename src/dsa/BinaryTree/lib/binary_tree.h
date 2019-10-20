#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdbool.h>

typedef char DataType;

struct Node {
    DataType value;
    struct Node* left;
    struct Node* right;
};

typedef struct Node* B_Tree;

void makenull_btree(B_Tree* root);
bool is_empty_btree(B_Tree root);
B_Tree merge_btree(DataType value, B_Tree first_tree, B_Tree second_tree);
void destroy_btree(B_Tree root);
DataType get_value(B_Tree node);
void preorder_btree(B_Tree root);
void inorder_btree(B_Tree root);
void postorder_btree(B_Tree root);

#endif

