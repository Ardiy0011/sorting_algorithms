#include "sort.h"
#include "swap.c"

/**
 * lomuto_partition - Lomuto partition scheme for quicksort
 * @array: The input array
 * @low: The lower bound index
 * @high: The higher bound index
 * @size: Number of elements in @array
 * Return: Index of the pivot after partitioning
 */
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
    int pivot = array[high];
    ssize_t i = low - 1, j;

    for (j = low; j < high; j++)
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

    if (i + 1 != high)
    {
        swap(&array[i + 1], &array[high]);
        print_array(array, size);
    }

    return (i + 1);
}

/**
 * quick_sort_helper - Recursive helper function for quicksort
 * @array: The input array
 * @low: The lower bound index
 * @high: The higher bound index
 * @size: Number of elements in @array
 */
void quick_sort_helper(int *array, ssize_t low, ssize_t high, size_t size)
{
    if (low < high)
    {
        size_t pivot_idx = lomuto_partition(array, low, high, size);

        quick_sort_helper(array, low, pivot_idx - 1, size);
        quick_sort_helper(array, pivot_idx + 1, high, size);
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
    if (array == NULL || size < 2)
        return;

    quick_sort_helper(array, 0, size - 1, size);
}
