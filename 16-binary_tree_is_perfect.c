#include "binary_trees.h"

/**
 * leaf - checks if a node is a leaf of abinary tree.
 * @node: pointer to the node to check.
 *
 * Return: 1 if the node is a leaf, 0 otherwise.
 */

unsigned char leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - returns the depth of a node in a binary tree.
 * @tree: pointer to the node to measure the depth of.
 *
 * Return: the depth of the node.
 */

size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_a_leaf - returns a leaf of a binary tree.
 * @tree: pointer to the node of the tree to find a leaf.
 *
 * Return: pointer to the first encountered leaf.
 */

const binary_tree_t *get_a_leaf(const binary_tree_t *tree)
{
	if (leaf(tree) == 1)
	{
		return (tree);
	}
	return (tree->left ? get_a_leaf(tree->left) : get_a_leaf(tree->right));
}

/**
 * perfect_recursive - checks if a binary tree is perfect recursively.
 * @tree: pointer to the root node of the tree to check.
 * @leaf_depth: depth of one leaf in the binary tree.
 * @level: level of the current node.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int perfect_recursive(const binary_tree_t *tree, size_t leaf_depth,
		size_t level)
{
	if (leaf(tree))
	{
		return (level == leaf_depth ? 1 : 0);
	}
	if (tree->left == NULL || tree->right == NULL)
	{
		return (0);
	}
	return (perfect_recursive(tree->left, leaf_depth, level + 1) &&
			perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 0 if the tree is null or not perfect, otherwise 1.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (perfect_recursive(tree, depth(get_a_leaf(tree)), 0));
}
