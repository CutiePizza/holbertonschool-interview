#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - swap two cases
 * @a: integer
 * @b: integer
 */

void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * heapify - Heapify an array
 * @array: array of integers to heapify
 * @n: size_t
 * @i: size_t
 * @size: size_t
 */

void heapify(int *array, size_t n, size_t i, size_t size)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < n && array[left] > array[largest])
		largest = left;

	if (right < n && array[right] > array[largest])
		largest = right;

	if (largest != i) //if root not largest
	{
		swap(&array[i], &array[largest]);
		print_array(array, size);
		heapify(array, n, largest, size);
	}
}

/**
 * heap_sort - heap sort array
 * @array: array of intgers
 * @size: size_t of array
 */

void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);
	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
        heapify(array, i, 0, size);
	}
}