#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
/**
 * tree_size_2- size_2 of tree recursively
 * @tree: root of tree
 * Return: double size of tree
 */
size_t tree_size_2(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (!tree)
		return (0);
	left = (1 + tree_size_2(tree->left));
	right = (1 + tree_size_2(tree->right));
	return (left + right);
}
/**
 * binary_tree_size_2- gives size of a binary tree
 * @tree: root of tree
 * Return: size of binary tree
 */
size_t binary_tree_size_2(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return ((tree_size_2(tree)) / 2);
}
/**
 * binary_tree_height_2- measure the highest high of a tree
 * @tree: root of tree
 * Return: height of a tree
 */
size_t binary_tree_height_2(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	left = (1 + binary_tree_height_2(tree->left));
	right = (1 + binary_tree_height_2(tree->right));

	if (left > right)
		return (left);
	return (right);
}
/**
 * binary_tree_is_perfect- shows if tree is perfect
 * @tree: root of tree
 * Return: 1 for perfect tree or 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, size, pow = 1, i = 0;

	height = binary_tree_height_2(tree) + 1;
	size = binary_tree_size_2(tree);
	for (i = 0; i < height; i++)
		pow *= 2;
	if ((pow - 1) == size)
		return (1);
	return (0);
}
