#include "sort.h"
#include <stdlib.h>


int maximum(int *array, size_t size)
{
  size_t i;
  int m = array[0];
  for (i = 1; i < size; i++)
  {
    if (array[i] > m)
    m = array[i];
  }
  return m;
}
/**
 * bubble_sort - bubble sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
unsigned int max;
size_t i;
int *count, *output, val;

max = maximum(array, size);
count = malloc(sizeof(size_t) * (max + 1));
output = malloc(sizeof(array));

for (i = 0; i <= max; i++)
count[i] = 0;

for(i = 0; i < size; i++)
  {
    val = array[i];
    count[val] += 1;
  }

for(i = 1; i <= max; i++)
  count[i] += count[i - 1];
print_array(count, max + 1);

for (i = 0; i < size; i++)
{
  output[count[array[i]] - 1] = array[i];
  count[array[i]]--;
}
for (i = 0; i < size; i++)
array[i] = output[i];

free(count);
free(output);
}