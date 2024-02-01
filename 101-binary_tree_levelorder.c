#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
* binary_tree_levelorder - Traverses a binary tree using level-order traversal
* @tree: A pointer to the root node of the tree to traverse
* @func: A pointer to a function to call for each node (value in the node
*        must be passed as a parameter to this function)
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
if (tree == NULL || func == NULL)
return;

{
const binary_tree_t **queue = malloc(sizeof(*queue) * 1024);
size_t front = 0, rear = 0;

if (queue == NULL)
return;

queue[rear++] = tree;

while (front < rear)
{
const binary_tree_t *current = queue[front++];

func(current->n);

if (current->left != NULL)
queue[rear++] = current->left;

if (current->right != NULL)
queue[rear++] = current->right;
}

free(queue);
}
}

