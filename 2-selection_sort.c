#include "sort.h"
/**
* selection_sort - Function to sort and array
* @array: Pointer to array given.
* @size: variable of array's size.
* Return: Nothing.
*/
void selection_sort(int *array, size_t size)
{
	int tmp2;
	size_t i = 0, tmp, iter;
	if (size < 2)
		return

	for (; i < size; i++)
	{
		tmp = i;
		tmp2 = tmp;
		for (iter = i; iter < size ; iter++)
		{
			if (array[iter] < array[tmp])
				tmp = iter;
		}
		tmp2 = array[i];
		array[i] = array[tmp];
		array[tmp] = tmp2;
		if (tmp != i)
			print_array(array, size);
	}
}
