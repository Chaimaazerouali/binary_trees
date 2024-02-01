#include "binary_trees.h"

/**
* binary_tree_uncle - Finds the uncle of a node
* @node: Pointer to the node to find the uncle
*
* Return: Pointer to the uncle node, or NULL if not found
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
if (!node || !node->parent || !node->parent->parent)
return NULL;

binary_tree_t *parent = node->parent;
binary_tree_t *grandparent = parent->parent;

if (grandparent->left == parent)
return grandparent->right;
else
return grandparent->left;
}

