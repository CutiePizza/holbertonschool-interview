#include "lists.h"

/**
 * insert_node - Insert a node in a sorted linked list
 * @head: Node
 * @number: number to add
 * Return: Address of new node
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node = NULL, *p;

	if (head == NULL)
		return (NULL);
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = number;
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else if ((*head)->n > number)
	{
		new_node->next = *head;
		*head = new_node;

	}
	else
	{
		p = *head;
		while (p->next != NULL && p->next->n < number)
			p = p->next;
		new_node->next = p->next;
		p->next = new_node;
	}
return (new_node);
}
