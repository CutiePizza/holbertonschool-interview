#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

void merge(int *arr, int begin, int mid, int end)
{
	int i, j, k;
	int n1 = mid - begin;
	int n2 = end - mid + 1;
	int L[n1], R[n2];

	printf("Merging...\n");
	for (i = 0; i < n1; i++)
		L[i] = arr[begin + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[mid + j];
	printf("[left]: ");
	print_array(L, n1);
	printf("[right]: ");
	print_array(R, n2);
	i = 0;
	j = 0;
	k = begin;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	printf("[Done]: ");
	print_array(&arr[begin], end - begin + 1);
}

void m_sort(int *array, int begin, int end)
{
	int mid, i;

	if (begin < end)
	{
		mid = begin + (end - begin + 1) / 2;

		m_sort(array, begin, mid - 1);
		m_sort(array, mid, end);
		merge(array, begin, mid, end);
	}
}

void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	m_sort(array, 0, (int)size - 1);
}
