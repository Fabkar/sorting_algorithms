#include "sort.h"
/**
* bubble_sort - Function to sort and array
* @array: Pointer to array given.
* @size: variable of array's size.
* Return: Nothing.
*/
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i = 0, j;

	for (; i < size; i++)
	{
		for (j = 0; j < (size - i); j++)
		{
			if (array[j - 1] > array[j])
			{
				tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
