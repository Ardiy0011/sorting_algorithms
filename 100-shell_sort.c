#include "sort.h"
#include "sorting_validation.c"
#include "swap.c"

/**
 * knuth_sequence_formula - implemetation of the knuth sequec
 * @size: Number of elements in @array
 * Return: The calculated gap value using the Knuth sequence.
 */
size_t knuth_sequence_formula(size_t size)
{
	size_t gap_value = 1;

	while (gap_value < size)
	{
	gap_value = gap_value * 3 + 1;
	}
	return (gap_value / 3);
}

/**
 * shell_sort - function that implements the shell sort
 * algorithm
 * @array: The input array
 * @size: Number of elements in @array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap_value = knuth_sequence_formula(size);
	size_t i, j;

	if (array == NULL || size <= 1)
    	return;

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
	gap_value = (gap_value - 1) / 3;
	print_array(array, size);
	}
}
