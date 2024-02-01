#include "binary_trees.h"

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
