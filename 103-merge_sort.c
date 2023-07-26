#include "sort.h"

/**
 * merge - Merge two sorted subarrays into a single sorted array.
 * @array: The input array.
 * @left: Pointer to the left subarray.
 * @lz: Size of the left subarray.
 * @right: Pointer to the right subarray.
 * @rz: Size of the right subarray.
 */
void merge(int *array, int *left, size_t lz, int *right, size_t rz)
{
	size_t i = 0, j = 0, k = 0;
	int *temp = (int *)malloc((lz + rz) * sizeof(int));

	if (temp == NULL)
	{
	printf("Memory allocation error!\n");
	return;
	}
	while (k < lz + rz)
	{
	switch ((i < lz) * 2 + (j < rz))
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
	for (i = 0; i < lz + rz; i++)
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
		size_t lz = mid;
		size_t rz = size - mid;

		int *left = array;
		int *right = array + mid;

		merge_sort(left, lz);
		merge_sort(right, rz);

		if (left[lz - 1] <= right[0])
		{
			return;
		}

		merge(array, left, lz, right, rz);

		print_array(array, size);
		}
}
