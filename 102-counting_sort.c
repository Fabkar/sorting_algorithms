#include "sort.h"
/**
 * counting_sort - Function to sort elements by counting occurrences.
 * @array: Pointer to array.
 * @size: size of array.
*/
void counting_sort(int *array, size_t size)
{
	int tmp, i, *new_array, *new_array2;

	tmp = array[0];
	if (!array || size < 2)
		return;
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > tmp)
			tmp = array[i];
	}
	new_array = malloc(sizeof(int) * tmp + 1);
	if (!new_array)
		return;
	for (i = 0; i <= tmp; i++)
		new_array[i] = 0;
	for (i = 0; i < (int)size; i++)
		new_array[array[i]]++;
	for (i = 0; i <= tmp; i++)
		new_array[i] += new_array[i - 1];
	print_array(new_array, tmp + 1);
	new_array2 = malloc(sizeof(int) * size);
	if (!new_array2)
	{
		free(new_array);
		return;
	}
	for (i = 0; i < (int)size; i++)
	{
		new_array2[new_array[array[i]] - 1] = array[i];
		new_array[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
	{
		array[i] = new_array2[i];
	}
	free(new_array);
	free(new_array2);
}
