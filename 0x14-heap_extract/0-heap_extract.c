#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * tree_size - return size of tree
 * @root: root of tree
 * Return: size of tree int
 */

int tree_size(heap_t *root)
{
	if (root == NULL)  
		return 0; 
	else     
		return(tree_size(root->left) + 1 + tree_size(root->right)); 
}
/**
 * heap_to_array - creates an array from heap
 * @array: new array
 * @node: node
 * @index: index to be put in
 */

void heap_to_array(heap_t **array, heap_t *node, int index)
{
	array[index] = node;
	if (node)
	{
		heap_to_array(array, node->left, (index * 2) + 1);
		heap_to_array(array, node->right, (index * 2) + 2);
	}
}
/**
 * rebuild - revuild the heap
 * @node : node
 */

void rebuild(heap_t *node)
{
	int tmp;

	if (node->left == NULL)
		return;
	else if (node->right == NULL || node->left->n >= node->right->n)
	{
		if (node->n < node->left->n)
		{
			tmp = node->n;
			node->n = node->left->n;
			node->left->n = tmp;
		}
		rebuild(node->left);
	}
	else if (node->left->n < node->right->n)
	{
		if (node->n < node->right->n)
		{
			tmp = node->n;
			node->n = node->right->n;
			node->right->n = tmp;
		}
		rebuild(node->right);
	}
}
/**
 * heap_extract - extract root node
 * @root: root of heap
 * Return: 0 if fails, value sotored in node
 */

int heap_extract(heap_t **root)
{
	int size, n;
	heap_t **array;

	if (!root || !*root)
		return(0);
	n = (*root)->n;
	size = tree_size(*root);
	array = calloc(2000, sizeof(heap_t *));
	if (array == NULL)
		return (0);
	heap_to_array(array, *root, 0);
	if (array[size - 1] == *root)
	{
		free(array);
		free(root);
		*root = NULL;
		return (n);
	}
	(*root)->n = array[size - 1]->n;
	if (array[size - 1]->parent->left == array[size - 1])
		array[size - 1]->parent->left = NULL;
	else
		array[size - 1]->parent->right = NULL;
	free(array[size - 1]);
	free(array);
	rebuild(*root);
	return (n);
}
