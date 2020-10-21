#include "sort.h"
/**
 * shell_sort - sorting by exchange or sorting by insertion.
 * @array: array elements to sort
 * @size: size array
 */
void shell_sort(int *array, size_t size)
{
	int tmp = 0;
	size_t itv, i, j;

	if (size < 2)
		return;

	for (itv = 0; itv <= (size / 3); itv = itv * 3 + 1)
	;
	for (; itv > 0; itv = (itv - 1) / 3)
	{
		for (i = itv; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= itv && array[j - itv] > tmp; j -= itv)
				array[j] = array[j - itv];
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
