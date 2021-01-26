#include "lists.h"
/**
* find_listint_loop - find if a list has a loop
* @head : head of the list
* Return: a node
*/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	if (!head || head->next == NULL)
		return (NULL);
	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			break;
	}
	if (slow == fast)
	{
		slow = head;
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next;
			if (slow == fast)
				return(slow);
		}
	}
	return (NULL);
}
