#include "sort.h"
#include "swap.c"
/**
 * bubble_sort - function that implements the bubble sort
 * algorithm
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (!array || size < 2)
	return;

	for (i = 0; i < size; i++)
	{
	for (j = 0; j < size - 1; j++)
	{
		if (array[j] > array[j + 1])
		{
		swap(&array[j], &array[j + 1]);
		print_array(array, size);

		}
	}
	}
}
