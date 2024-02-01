#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
* calculate_tree_size - size of tree recursively
* @tree: root of tree
* Return: double size of tree
*/
size_t calculate_tree_size(const binary_tree_t *tree)
{
int left = 0, right = 0;

if (!tree)
return (0);
left = (1 + calculate_tree_size(tree->left));
right = (1 + calculate_tree_size(tree->right));
return (left + right);
}

/**
* binary_tree_size - gives size of a binary tree
* @tree: root of tree
* Return: size of binary tree
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
if (!tree)
return (0);
return ((calculate_tree_size(tree)) / 2);
}

/**
* calculate_tree_height - measure the highest high of a tree
* @tree: root of tree
* Return: height of a tree
*/
size_t calculate_tree_height(const binary_tree_t *tree)
{
int left = 0, right = 0;

if (!tree)
return (0);
if (!tree->left && !tree->right)
return (0);
left = (1 + calculate_tree_height(tree->left));
right = (1 + calculate_tree_height(tree->right));

if (left > right)
return (left);
return (right);
}

/**
* is_perfect_tree - shows if tree is perfect
* @tree: root of tree
* Return: 1 for perfect tree or 0 otherwise
*/
int is_perfect_tree(const binary_tree_t *tree)
{
size_t height, size, pow = 1, i = 0;

height = calculate_tree_height(tree) + 1;
size = binary_tree_size(tree);
for (i = 0; i < height; i++)
pow *= 2;
if ((pow - 1) == size)
return (1);
return (0);
}

