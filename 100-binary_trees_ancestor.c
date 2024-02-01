#include <stddef.h>
#include "binary_trees.h"

/**
* binary_tree_depth - Measures the depth of a binary tree node.
* @node: A pointer to the node to measure the depth.
*
* Return: The depth of the node.
*/
size_t binary_tree_depth(const binary_tree_t *node)
{
size_t depth = 0;

while (node != NULL)
{
depth++;
node = node->parent;
}

return (depth);
}

/**
* binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
* @first: A pointer to the first node.
* @second: A pointer to the second node.
*
* Return: A pointer to the lowest common ancestor node. If no common ancestor
* was found, return NULL.
*/

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
size_t depth_first, depth_second;

if (first == NULL || second == NULL)
return (NULL);

depth_first = binary_tree_depth(first);
depth_second = binary_tree_depth(second);

while (depth_first > depth_second)
{
first = first->parent;
depth_first--;
}

while (depth_second > depth_first)
{
second = second->parent;
depth_second--;
}

while (first != NULL && second != NULL)
{
if (first == second)
return ((binary_tree_t *)first);

first = first->parent;
second = second->parent;
}

return (NULL);
}

