#include "binary_trees.h"

/**
 * bst_search - searches for a value in a binary search tree.
 * @tree: pointer to the root node of the bst to search.
 * @value: value to search for in the tree.
 *
 * Return: pointer to the node containing the value, otherwise NULL.
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
		{
			return ((bst_t *)tree);
		}
		if (tree->n > value)
		{
			return (bst_search(tree->left, value));
		}
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
