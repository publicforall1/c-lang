#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>

void makenull_bstree(BS_Tree* root){
    *root = NULL;
}

bool is_empty_bstree(BS_Tree root){
    return root == NULL;
}

void insert_node(KeyType value, BS_Tree* root){
    if (*root == NULL){
	BS_Tree node = (BS_Tree) malloc(sizeof(struct Node));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	*root = node;
    }

    if (value < (*root)->value)
	insert_node(value, &((*root)->left));
    if (value > (*root)->value)
	insert_node(value, &((*root)->right));
}

KeyType delete_max_node(BS_Tree* root){
    if (*root == NULL)
	return -1;
    if ((*root)->right == NULL){
	KeyType value = (*root)->value;
	BS_Tree node = *root;
	*root = (*root)->left;
	free(node);
	return value;
    }
    return delete_max_node(&((*root)->right));
}

void delete_node(KeyType value, BS_Tree* root){
    if (*root == NULL)
	return;
    if (value == (*root)->value){
	// node has 2 child
	if (((*root)->left != NULL) && ((*root)->right != NULL)){
	    (*root)->value = delete_max_node(&(*root)->left);
	    return;
	}

	BS_Tree node = *root;
	// node has only 1 child
	if ((*root)->left != NULL){
	    (*root) = (*root)->left;
	    free(node);
	    return;
	}
	if ((*root)->right != NULL){
	    (*root) = (*root)->right;
	    free(node);
	    return;
	}
	// node has no child
	(*root) = NULL;
	free(node);
	return;
    }

    if (value < (*root)->value)
	delete_node(value, &((*root)->left));
    if (value > (*root)->value)
	delete_node(value, &((*root)->right));
}

void destroy_bstree(BS_Tree root){
    if (root == NULL)
	return;
    destroy_bstree(root->right);
    destroy_bstree(root->left);
    free(root);
}

BS_Tree search(KeyType lookup_value, BS_Tree root){
    if (root == NULL)
	return NULL;
    if (root->value == lookup_value)
	return root;
    if (lookup_value < root->value)
	search(lookup_value, root->left);
    if (lookup_value > root->value)
	search(lookup_value, root->right);
}

void preorder_bstree(BS_Tree root){
    if (root == NULL)
	return;
    printf("%d ", root->value);
    preorder_bstree(root->left);
    preorder_bstree(root->right);
}

void inorder_bstree(BS_Tree root){
    if (root == NULL)
	return;
    inorder_bstree(root->left);
    printf("%d ", root->value);
    inorder_bstree(root->right);
}

void postorder_bstree(BS_Tree root){
    if (root == NULL)
	return;
    postorder_bstree(root->left);
    postorder_bstree(root->right);
    printf("%d ", root->value);
}

