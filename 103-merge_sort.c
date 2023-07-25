#include "sort.h"

/**
 * merge - Merge two sorted subarrays into a single sorted array.
 * @array: The input array.
 * @left: Pointer to the left subarray.
 * @left_size: Size of the left subarray.
 * @right: Pointer to the right subarray.
 * @right_size: Size of the right subarray.
 */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
    size_t i = 0, j = 0, k = 0;
    int *temp = (int *)malloc((left_size + right_size) * sizeof(int));

    if (temp == NULL)
    {
        printf("Memory allocation error!\n");
        return;
    }

    while (k < left_size + right_size)
    {
        switch ((i < left_size) * 2 + (j < right_size))
        {
            case 3:
                if (left[i] <= right[j])
                {
                    temp[k] = left[i];
                    i++;
                }
                else
                {
                    temp[k] = right[j];
                    j++;
                }
                break;

            case 2:
                temp[k] = left[i];
                i++;
                break;

            case 1:
                temp[k] = right[j];
                j++;
                break;
        }
        k++;
    }

    for (i = 0; i < left_size + right_size; i++)
    {
        array[i] = temp[i];
    }

    free(temp);
}

/**
 * merge_sort - Function that implements the top-down merge sort algorithm.
 * @array: The input array.
 * @size: Number of elements in @array.
 */
void merge_sort(int *array, size_t size)
{
    if (size > 1)
    {
        size_t mid = size / 2;
        size_t left_size = mid;
        size_t right_size = size - mid;

        int *left = array;
        int *right = array + mid;

        merge_sort(left, left_size);
        merge_sort(right, right_size);

        merge(array, left, left_size, right, right_size);

        print_array(array, size);
    }
}
