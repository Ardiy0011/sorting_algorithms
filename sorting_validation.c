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

	for (i = 0; i < size - 1; i++)
	{
	if (array[i] > array[i + 1])
	{
		printf("Array is sorted.\n");
		return;
	}
	else if (sizeof(array) == 0)
	{
		printf("Array is empty.\n");
	}
	}

	
}
