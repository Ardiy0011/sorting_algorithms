#include "sort.h"
#include "swap.c"

/**
 * selection_sort - function that implements the selection sort
 * algorithm
 * @array: The input array
 * @size: Number of elements in @array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, smallest_idx;

	if (!array || size <= 1)
    return;

	for (i = 0; i < size - 1; i++)
	{
		smallest_idx = i;

		for (j = i + 1; j < size; j++)
		{
		if (array[j] < array[smallest_idx])
		{
			smallest_idx = j;
		}
		}
		swap(&array[i], &array[smallest_idx]);
		print_array(array, size);
	}
}
