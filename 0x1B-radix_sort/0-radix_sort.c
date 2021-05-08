#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * getMax - get max int
 * @arr: array
 * @n: size of array
 * Return: max int
 */
int getMax(int arr[], size_t n)
{
	int mx = arr[0];
	size_t i;

	for (i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return (mx);
}
/**
 * countSort - count sort
 * @arr: array
 * @n:size array
 * @exp: current digit
 */
void countSort(int arr[], size_t n, int exp)
{
	int *output;
	int i, count[10] = { 0 };

	output = malloc(sizeof(int) * n);
	if (output == NULL)
		return;
	for (i = 0; i < (int)n; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	for (i = 0; i < (int)n; i++)
		arr[i] = output[i];
	print_array(arr, n);
	free(output);
}
/**
 * radix_sort - radix sort
 * @array: array
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int exp;
	int m = getMax(array, size);

    if (size < 2 || !array)
		return;
	for (exp = 1; m / exp > 0; exp *= 10)
		countSort(array, size, exp);
}
