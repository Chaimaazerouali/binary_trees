#include "binary_trees.h"

/**
* binary_tree_height - Measures the height of a binary tree
* @tree: Pointer to the root node of the tree to measure the height
*
* Return: Height of the binary tree, or 0 if tree is NULL
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
	{
		return (0);
	}
	else
	{
		left = (1 + binary_tree_height(tree->left));
		right = (1 + binary_tree_height(tree->right));
	}
	if (left > right)
		return (left);
	else
		return (right);
}
