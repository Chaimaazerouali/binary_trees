#include "binary_trees.h"

/**
* binary_tree_is_complete - Checks if a binary tree is complete
* @tree: Pointer to the root node of the tree to check
*
* Return: 1 if the tree is complete, 0 otherwise
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
int is_full = binary_tree_is_full(tree);

if (tree == NULL)
return (0);

if (is_full)
return (1);

return (0);
}

/**
* binary_tree_is_full - Checks if a binary tree is full
* @tree: Pointer to the root node of the tree to check
*
* Return: 1 if the tree is full, 0 otherwise
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
if (tree == NULL)
return (1);

if (binary_tree_height(tree->left) != binary_tree_height(tree->right))
return (0);

return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
}

/**
* binary_tree_height - Calculates the height of a binary tree
* @tree: Pointer to the root node of the tree
*
* Return: Height of the tree
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
size_t left_height, right_height;

if (tree == NULL)
return (0);

left_height = binary_tree_height(tree->left);
right_height = binary_tree_height(tree->right);

return (1 + (left_height > right_height ? left_height : right_height));
}

