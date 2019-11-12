#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

void makenull_btree(B_Tree* root) { *root = NULL; }

bool is_empty_btree(B_Tree root) { return root == NULL; }

B_Tree merge_btree(B_Tree_DataType value, B_Tree first_tree,
                   B_Tree second_tree) {
    B_Tree node = (B_Tree)malloc(sizeof(struct B_Tree_Node));
    // worst case: memory allocation got an error
    // how to handle this situation
    // ...........................
    node->value = value;
    node->left = first_tree;
    node->right = second_tree;
    return node;
}

void destroy_btree(B_Tree root) {
    if (root == NULL)
        return;
    destroy_btree(root->left);
    destroy_btree(root->right);
    free(root);
}

B_Tree_DataType get_value_from_btree(B_Tree node) {
    return (node == NULL ? -1 : node->value);
}

void preorder_btree(B_Tree root) {
    if (root == NULL)
        return;

    printf("%c ", get_value_from_btree(root));
    preorder_btree(root->left);
    preorder_btree(root->right);
}

void inorder_btree(B_Tree root) {
    if (root == NULL)
        return;

    inorder_btree(root->left);
    printf("%c ", get_value_from_btree(root));
    inorder_btree(root->right);
}
void postorder_btree(B_Tree root) {
    if (root == NULL)
        return;

    postorder_btree(root->left);
    postorder_btree(root->right);
    printf("%c ", get_value_from_btree(root));
}
