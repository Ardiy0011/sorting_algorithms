#include "sort.h"
#include "sorting_validation.c"
#include "swap.c"

/**
 * knuth_sequence - implemetation of the knuth sequec
 * @size: Number of elements in @array
 */
size_t knuth_sequence(size_t size)
{
	size_t gap_value = 1;

	while (gap_value < size)
	{
	gap_value = (gap_value * 3) + 1;
	}
	return ((gap_value - 1) / 3);
}

/**
 * shell_sort - function that implements the shell sort
 * algorithm
 * @array: The input array
 * @size: Number of elements in @array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap_value = knuth_sequence(size);
	size_t i, j;

	sorting_validation(array, size);

	while (gap_value > 0)
	{

	i = gap_value;
	while (i < size)
	{
		int temp = array[i];
		j = i;

		while (j >= gap_value && array[j - gap_value] > temp)
		{
		swap(&array[j], &array[j - gap_value]);
		j -= gap_value;
		}
		array[j] = temp;
		i++;
	}
	gap_value /= 2;
	print_array(array, size);
	}
}
