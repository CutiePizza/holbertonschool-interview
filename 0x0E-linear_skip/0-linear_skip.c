#include "search.h"

/**
 * search - search in nodes
 * @list: head of the skip list
 * @value: value to search for
 * Return: Node if value found, null if not
 */

skiplist_t *search(skiplist_t *list, int value)
{
	skiplist_t *s;

	for (s = list; s; s = s->next)
	{
		printf("Value checked at index [%lu] = [%lu]\n", s->index, s->n);
		if (s->n == value)
			return (s);   
	}
	return (NULL);
}
/**
 * linear_skip - look for a value
 * 
 * 
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	size_t i, j, idx;
	int n;
	skiplist_t *current, *express;

	if (!list)
		return (NULL);
	current = list;
	while (current)
	{
		if (current->express)
			express = current->express;
		else
		{
			express = current;
			while (express && express->next)
				express = express->next;
			i = current->index;
			j = express->index;
			printf("Value found between indexes [%lu] and [%lu]\n",
					i, j);
			return(search(current, value));
		}
		idx = express->index;
		n = express->n;
		printf("Value checked at index [%lu] = [%lu]\n", idx, n);
		if (express->n >= value)
		{
			i = current->index;
			j = express->index;
			printf("Value found between indexes [%lu] and [%lu]\n",
					i, j);
			return (search(current, value));
		}
		if (current->express)
			current = current->express;
		else
			break;
	}
	return (NULL);
}
