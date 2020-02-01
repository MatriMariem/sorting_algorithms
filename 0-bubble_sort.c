#include "sort.h"

/**
 * swap - function that swaps two integers
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

/**
 * bubble_sort - bubble sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int swapped = 1;

	if (!array || size < 2)
		return;
	while (swapped != 0)
	{
		swapped = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array + j, array + (j + 1));
				print_array((const int *)array, size);
				swapped = 1;
			}
		}
		i++;
		if (swapped == 0)
			break;
	}
}
