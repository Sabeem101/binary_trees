#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 0 if the tree is NULL.
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (recursive_full(tree));
}

/**
 * recursive_full - checks if a binary tree is full recursively.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is full, 0 otherwise.
 */

int recursive_full(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
			(tree->left == NULL && tree->right != NULL) ||
			recursive_full(tree->left) == 0 ||
			recursive_full(tree->right) == 0)
			return (0);
	}
	return (1);
}
