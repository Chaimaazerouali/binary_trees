#include "binary_trees.h"

/**
* binary_tree_is_leaf - Checks if a node is a leaf
* @node: Pointer to the node to check
*
* Return: 1 if node is a leaf, otherwise 0
*         If node is NULL, return 0
*/
int binary_tree_is_leaf(const binary_tree_t *node)
{
/* Check if node is NULL */
if (node == NULL)
return (0);

/* Check if node has no left or right child (i.e., is a leaf) */
return (node->left == NULL && node->right == NULL);
}

