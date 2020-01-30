#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
* swap - function that swaps two integers
* @a: integer
* @b: integer
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
* @size: size of array
*/
void bubble_sort(int *array, size_t size)
{
size_t i = 0, j = 0;

for (i = 0; i < size; i++)
{
for (j = 0; j < size; j++)
{
if (array[j] > array[j + 1])
{
swap(array + j, array + (j + 1));
print_array(array, size);
}
}
}
}
