#include "tree.h"
#include <stdio.h>

void makenull_tree(Tree* tree){
    tree->number_of_nodes = 0;
}

bool is_empty_tree(Tree tree){
    return tree.number_of_nodes == 0;
}

Node root_node(Tree tree){
    if (is_empty_tree(tree))
	return NIL;
    return 0;
    // return !is_empty_tree(tree) + NIL; -> magical code
}

DataType get_value(Node node, Tree tree){
    if (node >= tree.number_of_nodes)
	return NIL;
    return tree.labels[node];
}

void add_node(DataType value, Node parent, Tree* tree){
    tree->labels[tree->number_of_nodes] = value;
    tree->parents[tree->number_of_nodes] = parent;
    tree->number_of_nodes++;
}

Node parent(Node node, Tree tree){
    if (is_empty_tree(tree) || tree.number_of_nodes == 1)
	return NIL;
    return tree.parents[node];
}

Node left_child(Node node, Tree tree){
    Node checking_node = node;
    while(++node < tree.number_of_nodes)
	if (parent(node, tree) == checking_node)
	    return node;
    return NIL;
}

Node right_sibling(Node node, Tree tree){
    Node parent_of_checking_node = parent(node, tree);
    while(++node < tree.number_of_nodes)
	if (parent(node, tree) == parent_of_checking_node)
	    return node;
    return NIL;
}

void preorder(Node root, Tree tree){
    // argument notes: must pass root_node
    // preorder: root -> left-child -> right-sibling
    if (root == NIL)
	return;

    printf("%c ", get_value(root, tree));
    preorder(left_child(root, tree), tree);
    preorder(right_sibling(root, tree), tree);
}

void inorder(Node root, Tree tree){
    // argument notes: must pass root_node
    // inorder: left-child -> root -> right-sibling
    if (root == NIL)
	return;

    inorder(left_child(root, tree), tree);
    Node left = left_child(root, tree);
    if (left == NIL)
        printf("%c ", get_value(root, tree));
    Node parent_of_root = parent(root, tree);
    if (root == left_child(parent_of_root, tree))
	printf("%c ", get_value(parent_of_root, tree));

    inorder(right_sibling(root, tree), tree);
}

void postorder(Node root, Tree tree){
    // argument notes: must pass root_node
    // inorder: left-child -> right-sibling -> root
    if (root == NIL)
	return;

    postorder(left_child(root, tree), tree);
    printf("%c ", get_value(root, tree));
    postorder(right_sibling(root, tree), tree);
}

