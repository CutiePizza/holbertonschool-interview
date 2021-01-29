#include "search_algos.h"

/**
 * print_array - print array
 * @array: array
 * @start: Where to start to print
 * @end: end of printing
 */
void print_array(int *array, int start, int end)
{
	int i;

	for (i = start; i <= end; i++)
	{
		if (i == end)
			printf("%d\n", array[i]);
		else
			printf("%d, ", array[i]);
	}
}

/**
 * binary - Recursive algorithm for binary search
 * @array: array
 * @l: left of array
 * @r: right of array
 * @value: value to look for
 * Return: Index of located value or -1 if not found
 */

int binary(int *array, int l, int r, int value)
{
	int m;

    m = (r + l) / 2;
    if (array[m] ==  value && l == r)
        return (m);
	else if (l <= r)
	{
		print_array(array, l, r);
		if (array[m] >= value)
			return (binary(array, l, m, value));
		return (binary(array, m + 1, r, value));
	}
	return (-1);
}
/**
 * advanced_binary - Search for a given integer
 * @array: array of integer
 * @size: size or array
 * @value: value to look for
 * Return: Index of value
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size < 1)
		return (-1);
	return (binary(array, 0, (int)size - 1, value));
}
