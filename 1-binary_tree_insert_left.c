#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child if another node.
 * @parent: pointer to the node to insert the left child in.
 * @value: value to store in the new node.
 *
 * Return: a pointer to the created node, NULL on failure or if parent is NULL.
 * if parent has a left-child, the new node must take its place,
 * and the old node must be set as the left-child of the now node
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_lc;

	if (parent == NULL)
	{
		return (NULL);
	}
	new_lc = binary_tree_node(parent, value);
	if (new_lc == NULL)
	{
		return (NULL);
	}
	if (parent->left != NULL)
	{
		new_lc->left = parent->left;
		parent->left->parent = new_lc;
	}
	parent->left = new_lc;

	return (new_lc);
}
