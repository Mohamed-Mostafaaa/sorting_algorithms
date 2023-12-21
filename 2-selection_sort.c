#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: element to be sorted
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	int i, j, min_idx;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;

			if (min_idx != i)
			{
				*&array[min_idx] = *&array[i];
				*&array[i] = temp;
				print_array(array, size);
			}
		}
	}
}
