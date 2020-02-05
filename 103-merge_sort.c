#include "sort.h"

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm and
 * implementing the top-down merge sort algorithm
 * @array: the array of integers
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{

	if (!array || size < 2)
		return;
	split_merge(array, 0, (int)(size - 1));
}

/**
 * split_merge - splits the array into subarrays and
 * merge sort them using the top-down merge sort algorithm
 * @array: the array of integers
 * @first: index of first element
 * @last: index of last element
 */
void split_merge(int *array, int first, int last)
{
	int *arr;
	int i, n, mid;

	n = last - first + 1;
	if (n < 2)
		return;
	arr = malloc(sizeof(int) * n);
	if (!arr)
		return;
	for (i = 0; i < n; i++)
		arr[i] = array[first + i];
	mid = (n / 2) + first;
	printf("arr[0] %d arr[1] %d arr[2] %d\n\n", arr[0], arr[1], arr[2]);
	printf("first %d, mid %d, last %d\n\n", first, mid, last);
	split_merge(arr, first, mid - 1);
	split_merge(arr, mid, last);
	merging(array, arr, first, mid, last);
}

/**
 * merging - merges 2 sorted subarrays in an unsorted array
 * @array: the unsorted array
 * @arr: the array that contains the 2 subarrays separated by mid index
 * @first: index of first element in the first subarray
 * @mid: index of first element in the second subarray
 * @last: index of last element in second subarray
 */
void merging(int *array, int *arr, int first, int mid, int last)
{
	int i = 0, j = 0, k = 0, nl, nr;

	printf("Merging...\n");
	printf("[left]: ");
	print_array((const int *)arr, mid - first);
	printf("[right]: ");
	print_array((const int *)&arr[mid - first], last - mid + 1);

	nl = mid - first;
	nr = last - mid + 1;
	while (i < nl && j < nr)
	{
		if (arr[i] < arr[mid - first + j])
		{
			array[first + k] = arr[i];
			i++;
			k++;

		}
		else
		{
			array[first + k] = arr[mid - first + j];
			j++;
			k++;
		}
	}
	while (i < nl)
	{
		array[first + k] = arr[i];
		i++;
		k++;
	}
	while (j < nr)
	{
		array[first + k] = arr[mid - first + j];
		j++;
		k++;
	}
	free(arr);
	printf("[Done]: ");
	print_array((const int *)&array[first], last - first + 1);
}
