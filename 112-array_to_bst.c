#include "binary_trees.h"

/**
 * array_to_bst - buils a binary search tree from an array.
 * @array: pointer to the first element of the array to be converted.
 * @size: the number of elements in the array.
 *
 * Return: pointer to the root node of the created bst, or NULL on failure.
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t x, y;

	if (array == NULL)
	{
		return (NULL);
	}
	for (x = 0; x < size; x++)
	{
		for (y = 0; y < x; y++)
		{
			if (array[y] == array[x])
				break;
		}
		if (y == x)
		{
			if (bst_insert(&tree, array[x]) == NULL)
			{
				return (NULL);
			}
		}
	}
	return (tree);
}
