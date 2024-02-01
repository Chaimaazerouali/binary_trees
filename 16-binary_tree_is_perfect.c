#include "binary_trees.h"

/**
* binary_tree_is_perfect - Checks if a binary tree is perfect.
* @tree: A pointer to the root node of the tree to check.
*
* Return: 1 if the tree is perfect, 0 otherwise.
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

/* Get the depth of the leftmost leaf and the number of nodes */
int depth = 0, nodes = 0;
const binary_tree_t *temp = tree;

while (temp->left != NULL)
{
depth++;
temp = temp->left;
}

nodes = (1 << (depth + 1)) - 1;

/* Check if the number of nodes is equal to 2^depth - 1 */
return (nodes == binary_tree_size(tree));
}

