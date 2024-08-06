#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"


/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: Height of the tree. If tree is NULL, return 0.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_1, height_2;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	height_1 = binary_tree_height(tree->left); 
	height_2 = binary_tree_height(tree->right);

	if (height_1 > height_2)
		return (height_1 + 1);
	else
		return (height_2 + 1);
}
