#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child
 *				of another node.
 * @parent: pointer to the node to insert the right-child in.
 * @value: value to store in the new node.
 *
 * Return: pointer to the created node, NULL on failure of if parent is NULL.
 * If parent already has a right-child, the new node must tale its place,
 * and the old right-child must be set as the right-child of the new node.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_rc;

	if (parent == NULL)
	{
		return (NULL);
	}
	new_rc  = binary_tree_node(parent, value);
	if (new_rc == NULL)
	{
		return (NULL);
	}
	if (parent->right !=  NULL)
	{
		new_rc->right = parent->right;
		parent->right->parent = new_rc;
	}
	parent->right = new_rc;

	return (new_rc);
}
