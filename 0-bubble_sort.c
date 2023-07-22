#include "sort.h"
#include "swap.c"
#include "sorting_validation.c"

/**
 * bubble_sort - function that implements the bubble sort
 * algorithm
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    sorting_validation(array, size);

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                print_array(array, size);
            }
        }
    }
}
