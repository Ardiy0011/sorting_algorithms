#include "sort.h"

/**
 * sorting_validation - checks if list is sorted
 * algorithm
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void sorting_validation(int *array, size_t size)
{
	size_t i;

        if (!array || size < 2)
        return;

	for (i = 0; i < size; i++)
	{
	if (array[i] > array[i + 1])
	{
		return;
	}
	}

}
