#include "binary_trees.h"
#include <stdlib.h>
#include <string.h>

/**
 * binary_tree_node - Create a binary tree
 * @parent: Parent node of the node to create
 * @value: value of node to create
 * Return: new node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *tree;

	tree = malloc(sizeof(binary_tree_t));
	if (tree == NULL)
	{
		return (NULL);
	}
	tree->n = value;
	tree->parent = parent;
	tree->left = NULL;
	tree->right = NULL;
	return (tree);
}
