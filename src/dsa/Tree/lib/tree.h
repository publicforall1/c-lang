#ifndef TREE_H
#define TREE_H

#include <stdbool.h>

#define MAX_NODE_OF_TREE 100
#define TREE_NIL -1

typedef char Tree_DataType;
typedef int Tree_Node;

typedef struct {
    Tree_Node parents[MAX_NODE_OF_TREE];
    Tree_DataType labels[MAX_NODE_OF_TREE];
    int number_of_nodes;
} Tree;

bool is_empty_tree(Tree tree);
void makenull_tree(Tree* tree);
void add_node_to_tree(Tree_DataType value, Tree_Node parent, Tree* tree);
Tree_DataType get_value_from_tree(Tree_Node node, Tree tree);

Tree_Node tree_root_node(Tree tree);
Tree_Node tree_parent_of(Tree_Node node, Tree tree);
Tree_Node tree_left_child_of(Tree_Node node, Tree tree);
Tree_Node tree_right_sibling_of(Tree_Node node, Tree tree);

void preorder_tree(Tree_Node root, Tree tree);
void inorder_tree(Tree_Node root, Tree tree);
void postorder_tree(Tree_Node root, Tree tree);

#endif
