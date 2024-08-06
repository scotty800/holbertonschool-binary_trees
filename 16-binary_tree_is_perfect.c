#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_de - Measures the depth of a node in a binary tree
 * @node: Pointer to the node to measure the depth
 * Return: Depth of the node. If node is NULL, return 0.
 */
static int binary_tree_de(const binary_tree_t *node)
{
	int depth = 0;

	while (node && node->parent)
	{
		depth++;
		node = node->parent;
	}

	return (depth);
}

/**
 * binary_tree_recur - Checks if the binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * * @depth: Depth of the current node
 * @level: Current level of the node
 * Return: 1 if the tree is perfect, 0 otherwise
 */
static int binary_tree_recur(const binary_tree_t *tree, int depth, int level)
{

	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (binary_tree_recur(tree->left, depth, level + 1) &&
			binary_tree_recur(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth;

	if (tree == NULL)
		return (0);

	depth = binary_tree_de(tree);

	return (binary_tree_recur(tree, depth, 0));
}
