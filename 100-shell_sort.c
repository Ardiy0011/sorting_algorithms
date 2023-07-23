#include "sort.h"
#include "sorting_validation.c"
#include "swap.c"



void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}

size_t knuth_sequence(size_t size) {
    size_t gap_value = 1;
    while (gap_value < size) {
        gap_value = (gap_value * 3) + 1;
    }
    return (gap_value - 1) / 3;
}


void shell_sort(int *array, size_t size) {
    size_t gap_value = knuth_sequence(size);
    size_t i, j;
    sorting_validation(array, size);


    while (gap_value > 0) {

        i = gap_value;
        while (i < size) {
            int temp = array[i];
            j = i;
            while (j >= gap_value && array[j - gap_value] > temp) {
                swap(&array[j], &array[j - gap_value]);
                j -= gap_value;
            }
            array[j] = temp;
            i++;
        }
        gap_value /= 2;
        print_array(array, size);
    }
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    shell_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}