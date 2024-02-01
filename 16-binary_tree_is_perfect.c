#include "binary_trees.h"

/**
* binary_tree_is_perfect - Checks if a binary tree is perfect
* @tree: Pointer to the root node of the tree to check
*
* Return: 1 if the tree is perfect, 0 otherwise
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
int left_depth, right_depth;

if (tree == NULL)
return (0);

left_depth = binary_tree_depth(tree->left);
right_depth = binary_tree_depth(tree->right);

if (left_depth == right_depth)
{
if (tree->left == NULL && tree->right == NULL)
return (1);
return (binary_tree_is_perfect(tree->left) &&
binary_tree_is_perfect(tree->right));
}

return (0);
}

/**
* binary_tree_depth - Calculates the depth of a binary tree
* @tree: Pointer to the root node of the tree
*
* Return: Depth of the tree
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
size_t depth = 0;

while (tree != NULL)
{
depth++;
tree = tree->left;
}

return (depth);
}

