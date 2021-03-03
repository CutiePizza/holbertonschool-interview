#include <stdlib.h>
#include <stdio.h>
#include "list.h"
/**
 * add_node_end - add node at the end of linked list
 * @list: given list
 * @str: string to add in list
 * Return: new node
 */
List *add_node_end(List **list, char *str)
{
	List *new_node = NULL;
	List *tmp;

  if (!list)
    return (NULL);
	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);
	new_node->str = str;
	if ((*list) == NULL)
	{
		*list = new_node;
		(*list)->next = *list;
		(*list)->prev = *list;
		return (new_node);
	}
	tmp = *list;
	while (tmp)
	{
		if (tmp->next == *list)
			break;
		tmp = tmp->next;
	}
	new_node->next = tmp->next;
	tmp->next = new_node;
	new_node->prev = tmp;
	new_node->next->prev = new_node;
	return  (new_node);
}
/**
 * add_node_begin - add node at the begining
 * @list: list of chats
 * @str: string to add
 * Return: new node
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node = NULL;

  if (!list)
    return (NULL);
	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);
	new_node->str = str;
	if ((*list) == NULL)
	{
		*list = new_node;
		(*list)->next = *list;
		(*list)->prev = *list;
		return (new_node);
	}
	new_node->next = *list;
	new_node->prev = (*list)->prev;
	(*list)->prev = new_node;
	new_node->prev->next = new_node;
	(*list) = new_node;
	return (new_node);
}
