#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
* binary_tree_is_complete - Checks if a binary tree is complete
* @tree: Pointer to the root node of the tree to check
*
* Return: 1 if the tree is complete, 0 otherwise
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

/* Initialize a queue for level order traversal */
binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 1024);
if (queue == NULL)
return (0);

int front = 0, rear = 0;
int null_seen = 0;

queue[rear++] = (binary_tree_t *)tree;

while (rear - front > 0)
{
binary_tree_t *current = queue[front++];

/* Check for null nodes */
if (current == NULL)
null_seen = 1;
else
{
/* If a null node was seen previously, the tree is not complete */
if (null_seen)
{
free(queue);
return (0);
}

/* Enqueue left and right children */
queue[rear++] = current->left;
queue[rear++] = current->right;
}
}

/* If the loop completes, the tree is complete */
free(queue);
return (1);
}

