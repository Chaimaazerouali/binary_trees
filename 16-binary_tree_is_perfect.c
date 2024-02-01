#include "binary_trees.h"

/**
* binary_tree_height - Measures the height of a binary tree.
* @tree: A pointer to the root node of the tree.
*
* Return: The height of the tree.
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
size_t left_height, right_height;

if (tree == NULL)
return (0);

left_height = binary_tree_height(tree->left);
right_height = binary_tree_height(tree->right);

return ((left_height > right_height ? left_height : right_height) +1);
}

/**
* binary_tree_is_perfect - Checks if a binary tree is perfect.
* @tree: A pointer to the root node of the tree.
*
* Return: 1 if the tree is perfect, 0 otherwise. If tree is NULL, return 0.
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
size_t left_height, right_height;

if (tree == NULL)
return (0);

