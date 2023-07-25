#include "sort.h"
#include "swap.c"

/**
 * lomuto_partition - Lomuto partition scheme for quicksort
 * @array: The input array
 * @before: The beforeer bound index
 * @after: The afterer bound index
 * @size: Number of elements in @array
 * Return: Index of the pivot after partitioning
 */
size_t lomuto_partition(int *array, ssize_t before, ssize_t after, size_t size)
{
	int pivot = array[after];
	ssize_t i = before - 1, j;

	for (j = before; j < after; j++)
	{
		if (array[j] <= pivot)
		{
		i++;
		if (i != j)
		{
			swap(&array[i], &array[j]);
		}
		}
	}

	if (i + 1 != after)
	{
		swap(&array[i + 1], &array[after]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_recursion - Recursive recursion function for quicksort
 * @array: The input array
 * @before: The beforeer bound index
 * @after: The afterer bound index
 * @size: Number of elements in @array
 */
void quick_sort_recursion(int *array, ssize_t before, ssize_t after, size_t size)
{
	if (before < after)
	{
	size_t pivot_idx = lomuto_partition(array, before, after, size);

	quick_sort_recursion(array, before, pivot_idx - 1, size);
	quick_sort_recursion(array, pivot_idx + 1, after, size);
	}
}

/**
 * quick_sort - function that implements the quick sort
 * algorithm
 * @array: The input array
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{


	quick_sort_recursion(array, 0, size - 1, size);
}
