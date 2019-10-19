#ifndef TREE_H
#define TREE_H

#include <stdbool.h>

#define MAX_LENGTH 100
#define NIL -1

typedef char DataType;
typedef int Node;

typedef struct {
    Node parents[MAX_LENGTH];
    DataType labels[MAX_LENGTH];
    int number_of_nodes;
} Tree;

bool is_empty_tree(Tree tree);
void makenull_tree(Tree* tree);
void add_node(DataType value, Node parent, Tree* tree);
DataType get_value(Node node, Tree tree);

Node root_node(Tree tree);
Node parent(Node node, Tree tree);
Node left_child(Node node, Tree tree);
Node right_sibling(Node node, Tree tree);

void preorder(Node node, Tree tree);
void inorder(Node node, Tree tree);
void postorder(Node node, Tree tree);

#endif

