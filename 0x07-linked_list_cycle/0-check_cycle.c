#include "lists.h"

/**
 * check_cycle - Find if a list has a cycle
 * @list: head of the list
 * Return: 0 if has no cycle or 1 otherwise
 */
 
 int check_cycle(listint_t *list) 
 {
     listint_t *slow = *list, *fast = *list;

     if (list == NULL)
         return (0);
     while (slow != fast || fast != NULL)
     {
         fast = fast->next->next;
         slow = slow->next;
     }
     if (slow == fast)
         return (1);
     else
        return (0);

 }