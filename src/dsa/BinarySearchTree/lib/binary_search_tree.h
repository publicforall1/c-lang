#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdbool.h>

typedef int BS_Tree_KeyType;

struct BS_Tree_Node {
    BS_Tree_KeyType value;
    struct BS_Tree_Node* left;
    struct BS_Tree_Node* right;
};

typedef struct BS_Tree_Node* BS_Tree;

void makenull_bstree(BS_Tree*);
bool is_empty_bstree(BS_Tree);
void insert_node_to_bstree(BS_Tree_KeyType, BS_Tree*);
void destroy_bstree(BS_Tree);
BS_Tree search_in_bstree(BS_Tree_KeyType, BS_Tree);
BS_Tree_KeyType delete_max_node_from_bstree(BS_Tree*);
void delete_node_from_bstree(BS_Tree_KeyType, BS_Tree*);
void preorder_bstree(BS_Tree);
void inorder_bstree(BS_Tree);
void postorder_bstree(BS_Tree);

#endif
