#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * len - get length of linked list
 * @head: head of list
 * Return: length of linked list
 */

int len(listint_t *head)
{
	listint_t *p = head;
	int i = 0;

	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return (i);
}

/**
 * convert_array - convert linked list into array
 * @head: head of list
 * Return: new array
 */

int *convert_array(listint_t *head)
{
	int l = len(head);
	int *arr = malloc(sizeof(char) * l);
	int i = 0;
	listint_t *p = head;

	while (p != NULL)
	{
		arr[i] = p->n;
		p = p->next;
		i++;
	}
	return (arr);
}

/**
 * is_palindrome - check if lists palindrome or not
 * @head: head of list
 * Return: 1 if palindrome, 0 otherwise (empty list is palindrome)
 */

int is_palindrome(listint_t **head)
{
	int *p;
	int i, l, flag;

	if (*head == NULL)
		return (1);
	p = convert_array(*head);
	l = len(*head);
	for (i = 0; i < l / 2; i++)
	{
		if (p[i] != p[l - i - 1])
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
		return (0);
	return (1);
}
