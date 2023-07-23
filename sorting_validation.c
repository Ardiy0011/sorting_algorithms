#include "sort.h"

void sorting_validation(int *array, size_t size)
{
    size_t i;

    if (size == 0)
    {
        printf("empty array.\n");
        return;
    }

    for (i = 0; i < size - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            break;
        }
    }

    if (i == size - 1)
    {
        
        printf("Array already sorted: O(n)\n");
        return;
    }
}