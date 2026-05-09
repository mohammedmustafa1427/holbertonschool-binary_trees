#include "binary_trees.h"

/**
 * tree_height - Helper function to measure height for balance.
 * @tree: Pointer to the root.
 * Return: Height of the tree.
 */
size_t tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = tree->left ? 1 + tree_height(tree->left) : 1;
		size_t r = tree->right ? 1 + tree_height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure.
 *
 * Return: The balance factor. If tree is NULL, return 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return ((int)tree_height(tree->left) - (int)tree_height(tree->right));
}
