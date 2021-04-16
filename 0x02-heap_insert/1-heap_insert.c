#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * heap_insert - function that inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value stored in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL, *tree = NULL;

	if (!root)
		return (NULL);
	/* add first node  */
	if ((*root) == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		(*root) = new_node;
		return (new_node);
	}
	tree = (*root);
	/* handle tree */
	while (tree != NULL)
	{
		if (tree->left == NULL)
		{
			/* add left */
			new_node = binary_tree_node(tree, value);
			if (new_node == NULL)
				return (NULL);
			tree->left = new_node;
			new_node = heapify(tree->left);
			return (new_node);
		}
		else if (tree->right == NULL)
		{
			/* add right */
			new_node = binary_tree_node(tree, value);
			if (new_node == NULL)
				return (NULL);
			tree->right = new_node;
			new_node = heapify(tree->right);
			return (new_node);
		}
		tree = traverse(tree);
	}
	return (NULL);
}

/**
 * traverse - function that parses the tree and engages on the appropriate path
 * for adding a node
 * @tree: pointer to the tree
 * Return: n/a
 */

heap_t *traverse(heap_t *tree)
{
	int left_perfect = 0, right_perfect = 0;
	int left_height = 0, right_height = 0;

	left_perfect = binary_tree_is_perfect(tree->left);
	right_perfect = binary_tree_is_perfect(tree->right);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if ((left_perfect && right_perfect
	     && (left_height == right_height))
	    || (!left_perfect && right_perfect
		&& (left_height != right_height)))
		tree = tree->left;
	else
		tree = tree->right;
	return (tree);
}

/**
 * heapify - function that "relocates" an added node where appropriate
 * for a max heap binary tree (parent node must be the max node)
 * @new_node: pointer to the added node
 * Return: pointer to the "relocated" added node
 */

heap_t *heapify(heap_t *new_node)
{
	int value = 0;

	if (!new_node || new_node->parent == NULL)
		return (new_node);
	while (new_node->parent != NULL)
	{
		if (new_node->n < new_node->parent->n)
			return (new_node);
		value = new_node->n;
		new_node->n = new_node->parent->n;
		new_node->parent->n = value;
		new_node = new_node->parent;
	}
	return (new_node);
}

/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height
 * Return: height of tree, 0 if !tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	if (left_height >= right_height)
		return (left_height + 1);
	return (right_height + 1);
}

/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree
 * Return: 1 if tree is perfect, 0 otherwise or if !tree
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth = 0;
	const binary_tree_t *temp = NULL;

	if (!tree)
		return (0);

	/* evaluate the depth of the leftmost leaf */
	temp = tree;
	while (temp != NULL)
		depth++, temp = temp->left;

	/* call the return value of is_perfect recursion */
	return (is_perfect(tree, depth, 0));
}

/**
 * is_perfect - recursion function, helper to binary_tree_is_perfect
 * @tree: a pointer to the root node of the tree
 * @depth: depth of the leftmost leaf
 * @level: level in the tree
 * Return: 1 if tree is perfect, 0 otherwise
 */

int is_perfect(const binary_tree_t *tree, int depth, int level)
{
	if (!tree)
		return (1);

	/* compare the depth of the leftmost leaf & current node level */
	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);

	/* all parent nodes should have 2 children nodes */
	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect(tree->left, depth, level + 1) &&
		is_perfect(tree->right, depth, level + 1));
}
