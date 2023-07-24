#include "sort.h"
/**
 * swap - function that sways the positions of 2 integers
 * @first_int: pointer to the firist integer
 * @second_int: pointer to the 2nd integer
 */
void swap(int *first_int, int *second_int)
{
	int temp = *first_int;
	*first_int = *second_int;
	*second_int = temp;
}
