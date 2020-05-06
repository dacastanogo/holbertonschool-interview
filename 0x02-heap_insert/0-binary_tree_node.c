#include "binary_trees.h"
#include<stdlib.h>
/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to a parent node
 * @value: value for a new node
 * Return: a pointer to a new node or NULL
 */


binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
		binary_tree_t *new;

		new = malloc(sizeof(binary_tree_t));
				if (new == NULL)
				return (NULL);

		new->n = value;
		new->left = NULL;
		new->right = NULL;
		new->parent = parent;

		return (new);
}