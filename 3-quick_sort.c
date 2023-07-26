#include "sort.h"
#include "swap.c"

/**
 * lomuto_partition - Lomuto partition scheme for quicksort
 * @array: The input array
 * @be: The beforer bound index
 * @af: The afer bound index
 * @size: Number of elements in @array
 * Return: Index of the pivot af partitioning
 */
size_t lomuto_seq(int *array, ssize_t be, ssize_t af, size_t size)
{
	int pivot = array[af];
	ssize_t i = be - 1, j;

	for (j = be; j < af; j++)
	{
		if (array[j] <= pivot)
		{
		i++;
		if (i != j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
		}
	}

	if (i + 1 != af)
	{
		swap(&array[i + 1], &array[af]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_recursion - Recursive recursion function for quicksort
 * @array: The input array
 * @be: The beforer bound index
 * @af: The after bound index
 * @size: Number of elements in @array
 */
void qs_recursion(int *array, ssize_t be, ssize_t af, size_t size)
{
	if (be < af)
	{
	size_t pivot_idx = lomuto_partition(array, be, af, size);

	quick_sort_recursion(array, be, pivot_idx - 1, size);
	quick_sort_recursion(array, pivot_idx + 1, af, size);
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
	if (array == NULL || size <= 1)
	return;

	quick_sort_recursion(array, 0, size - 1, size);
}
