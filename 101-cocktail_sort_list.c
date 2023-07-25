#include "sort.h"

/**
 * swap - function that sways the positions of 2 integers
 * @first_int: pointer to the first integer
 * @second_int: pointer to the 2nd integer
 */
void swap(int *first_int, int *second_int)
{
	int temp = *first_int;
	*first_int = *second_int;
	*second_int = temp;
}

/**
 * bubble_sort - function that implements the bubble sort
 * algorithm
 * @array: The array to be printed
 * @size: Number of elements in @array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (array == NULL || size <= 1)
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
