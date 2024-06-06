#include "binary_trees.h"

/**
 * bst_insert - inserts a vakue in a binary search tree.
 * @tree: double pointer to the root node of the bst to insert the value.
 * @value: value to store in the node to be inserted.
 *
 * Return: pointer to the created node, or NULL on failure.
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current, *created;

	if (tree != NULL)
	{
		current = *tree;
		if (current == NULL)
		{
			created = binary_tree_node(current, value);
			if (created == NULL)
				return (NULL);
			return (*tree = created);
		}
		if (value < current->n)
		{
			if (current->left != NULL)
			{
				return (bst_insert(&current->left, value));
			}
			created = binary_tree_node(current, value);
			if (created == NULL)
				return (NULL);
			return (current->left = created);
		}
		if (value > current->n)
		{
			if (current->right != NULL)
			{
				return (bst_insert(&current->right, value));
			}
			created = binary_tree_node(current, value);
			if (created == NULL)
				return (NULL);
			return (current->right = created);
		}
	}
	return (NULL);
}
