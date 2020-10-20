#include "sort.h"
/**
* part - Function to make a partition of array.
* @array: pointer to array given.
* @left: pointer at begin array.
* @right: pointer at the end of array.
* @size: size of array.
* Return: Integer to use as a pivot.
*/
int part(int *array, int left, int right, size_t size)
{
	int i = left, piv = array[right], tmp = left, tmp2;

	for (; i < right; i++)
	{
		if (array[i] < piv)
		{
			tmp2 = array[i];
			array[i] = array[tmp];
			array[tmp] = tmp2;
			if (array[i] != array[tmp])
				print_array(array, size);
			tmp++;
		}
	}
	tmp2 = array[tmp];
	array[tmp] = array[right];
	array[right] = tmp2;
	if (array[tmp] != array[right])
		print_array(array, size);
	return (tmp);
}
/**
* quicksort - Function to sort a little bit fast an array.
* @array: pointer to array given.
* @left: pointer at begin array.
* @right: pointer at the end of array.
* @size: size of array.
* Return: Nothing.
 */
void quicksort(int *array, int left, int right, size_t size)
{
	int pivot;

	if (left > right)
		return;
	pivot = part(array, left, right, size);
	quicksort(array, left, pivot - 1, size);
	quicksort(array, pivot + 1, right, size);
}
/**
 * quick_sort - fucntion to sort an array using a pivot.
 * @array: Pointer to array given.
 * @size: size of array.
 * Return: Nothing.
 */
void quick_sort(int *array, size_t size)
{
	quicksort(array, 0, size - 1, size);
}
