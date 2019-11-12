#include "tree.h"
#include <stdio.h>

void makenull_tree(Tree* tree) { tree->number_of_nodes = 0; }

bool is_empty_tree(Tree tree) { return tree.number_of_nodes == 0; }

Tree_Node tree_root_node(Tree tree) {
    if (is_empty_tree(tree))
        return TREE_NIL;
    return 0;
    // return !is_empty_tree(tree) + TREE_NIL; -> magical code
}

Tree_DataType get_value_from_tree(Tree_Node node, Tree tree) {
    if (node >= tree.number_of_nodes || node == TREE_NIL)
        return '\0';
    return tree.labels[node];
}

void add_node_to_tree(Tree_DataType value, Tree_Node tree_parent_of,
                      Tree* tree) {
    tree->labels[tree->number_of_nodes] = value;
    tree->parents[tree->number_of_nodes] = tree_parent_of;
    tree->number_of_nodes++;
}

Tree_Node tree_parent_of(Tree_Node node, Tree tree) {
    if (is_empty_tree(tree) || tree.number_of_nodes == 1)
        return TREE_NIL;
    return tree.parents[node];
}

Tree_Node tree_left_child_of(Tree_Node node, Tree tree) {
    Tree_Node checking_node = node;
    while (++node < tree.number_of_nodes)
        if (tree_parent_of(node, tree) == checking_node)
            return node;
    return TREE_NIL;
}

Tree_Node tree_right_sibling_of(Tree_Node node, Tree tree) {
    Tree_Node parent_of_checking_node = tree_parent_of(node, tree);
    while (++node < tree.number_of_nodes)
        if (tree_parent_of(node, tree) == parent_of_checking_node)
            return node;
    return TREE_NIL;
}

void preorder_tree(Tree_Node root, Tree tree) {
    // argument notes: must pass tree_root_node
    // preorder_tree: root -> left-child -> right-sibling
    if (root == TREE_NIL)
        return;

    printf("%c ", get_value_from_tree(root, tree));
    preorder_tree(tree_left_child_of(root, tree), tree);
    preorder_tree(tree_right_sibling_of(root, tree), tree);
}

void inorder_tree(Tree_Node root, Tree tree) {
    // argument notes: must pass tree_root_node
    // inorder_tree: left-child -> root -> right-sibling
    if (root == TREE_NIL)
        return;

    inorder_tree(tree_left_child_of(root, tree), tree);
    Tree_Node left = tree_left_child_of(root, tree);
    if (left == TREE_NIL)
        printf("%c ", get_value_from_tree(root, tree));
    Tree_Node parent_of_root = tree_parent_of(root, tree);
    if (root == tree_left_child_of(parent_of_root, tree))
        printf("%c ", get_value_from_tree(parent_of_root, tree));

    inorder_tree(tree_right_sibling_of(root, tree), tree);
}

void postorder_tree(Tree_Node root, Tree tree) {
    // argument notes: must pass tree_root_node
    // postorder: left-child -> right-sibling -> root
    if (root == TREE_NIL)
        return;

    postorder_tree(tree_left_child_of(root, tree), tree);
    printf("%c ", get_value_from_tree(root, tree));
    postorder_tree(tree_right_sibling_of(root, tree), tree);
}
