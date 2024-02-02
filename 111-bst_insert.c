#include "binary_trees.h"
#include <stdlib.h>

/**
* bst_insert - Inserts a value in a Binary Search Tree
* @tree: A double pointer to the root node of the BST to insert the value
* @value: The value to store in the node to be inserted
*
* Return: A pointer to the created node, or NULL on failure
*/
bst_t *bst_insert(bst_t **tree, int value)
{
/* Check if tree is NULL */
if (tree == NULL)
return NULL;

/* Check if the tree is empty, create a new node and make it the root */
if (*tree == NULL)
{
*tree = binary_tree_node(NULL, value);
return *tree;
}

/* If the value is less than the current node's value, insert into the left subtree */
if (value < (*tree)->n)
{
/* If the left child is NULL, create a new node and return it */
if ((*tree)->left == NULL)
{
(*tree)->left = binary_tree_node(*tree, value);
return (*tree)->left;
}
/* Recursively insert into the left subtree */
return bst_insert(&(*tree)->left, value);
}
/* If the value is greater, insert into the right subtree */
else if (value > (*tree)->n)
{
/* If the right child is NULL, create a new node and return it */
if ((*tree)->right == NULL)
{
(*tree)->right = binary_tree_node(*tree, value);
return (*tree)->right;
}
/* Recursively insert into the right subtree */
return bst_insert(&(*tree)->right, value);
}

/* Value is already present, ignore and return NULL */
return NULL;
}

