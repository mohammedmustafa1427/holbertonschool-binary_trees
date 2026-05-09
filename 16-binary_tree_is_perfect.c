#include "binary_trees.h"

/**
 * tree_h - Helper to get height and size.
 * @tree: Pointer to root.
 *
 * Return: Height of the tree.
 */
size_t tree_h(const binary_tree_t *tree)
{
        if (tree == NULL)
                return (0);
        return (1 + tree_h(tree->left));
}

/**
 * is_p - Recursive helper for perfect check.
 * @tree: Pointer to root.
 * @h: Height.
 * @level: Current level.
 * Return: 1 if perfect.
 */
int is_p(const binary_tree_t *tree, size_t h, size_t level)
{
	if (tree->left == NULL && tree->right == NULL)
		return (h == level + 1);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_p(tree->left, h, level + 1) && is_p(tree->right, h, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node.
 * Return: 1 if perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t h;

	if (tree == NULL)
		return (0);
	h = tree_h(tree);
	return (is_p(tree, h, 0));
}
