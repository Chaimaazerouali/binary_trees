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
