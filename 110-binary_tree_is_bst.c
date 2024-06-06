#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if a binary tree is a valid binary tree search.
 * @tree: pointer to the node of the tree to check.
 *
 * Return: 1 is the tree is a valid bst, otherwise 0.
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (bst_helper(tree, INT_MIN, INT_MAX));
}

/**
 * bst_helper - helps check is a binary tree is valid binary search tree.
 * @tree: pointer to the root node of the tree to check.
 * @micro: the value of the smalledt node visited.
 * @macro: the value of the largest node visited.
 *
 * Return: 1 if the tree is a valid bst, 0 otherwise.
 */

int bst_helper(const binary_tree_t *tree, int micro, int macro)
{
	if (tree != NULL)
	{
		if (tree->n < micro || tree->n > macro)
		{
			return (0);
		}
		return (bst_helper(tree->left, micro, tree->n - 1) &&
				bst_helper(tree->right, tree->n + 1, macro));
	}
	return (1);
}
