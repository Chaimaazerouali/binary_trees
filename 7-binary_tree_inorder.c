#include "binary_trees.h"

/**
* binary_tree_inorder - Goes through a binary tree using in-order traversal
* @tree: Pointer to the root node of the tree to traverse
* @func: Pointer to a function to call for each node
*
* Description: If tree or func is NULL, do nothing
*/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
/* Check if tree or func is NULL, and if so, do nothing */
if (tree == NULL || func == NULL)
return;

/* Recursively traverse the left subtree in in-order */
binary_tree_inorder(tree->left, func);

/* Call the function on the value of the current node */
func(tree->n);

/* Recursively traverse the right subtree in in-order */
binary_tree_inorder(tree->right, func);
}

