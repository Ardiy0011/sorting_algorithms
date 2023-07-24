#include "sort.h"

void sorting_validation(int *array, size_t size)
{
    size_t i;

    for (i = 0; i < size - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            break;
        }
    }

}