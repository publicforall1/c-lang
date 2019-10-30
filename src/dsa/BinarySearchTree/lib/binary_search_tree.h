#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdbool.h>

typedef int KeyType;

struct Node {
    KeyType value;
    struct Node* left;
    struct Node* right;
};

typedef struct Node* BS_Tree;

void makenull_bstree(BS_Tree*);
bool is_empty_bstree(BS_Tree);
void insert_node(KeyType, BS_Tree*);
void destroy_bstree(BS_Tree);
BS_Tree search(KeyType, BS_Tree);
KeyType delete_max_node(BS_Tree*);
void delete_node(KeyType, BS_Tree*);
void preorder_bstree(BS_Tree);
void inorder_bstree(BS_Tree);
void postorder_bstree(BS_Tree);

#endif

