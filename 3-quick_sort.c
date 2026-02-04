#include "sort.h"

/**
 * swap_int - swaps two integers in an array
 * @a: pointer to first integer
 * @b: pointer to second integer
 */
void swap_int(int *a, int *b)
{
	int temp;

	if (a != b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}

/**
 * lomuto_partition - partitions an array using the Lomuto scheme
 * @array: array to partition
 * @low: starting index
 * @high: ending index (pivot)
 * @size: size of the array (for printing)
 *
 * Return: index of the pivot after partition
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	size_t i, j;

	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] < array[high])
		{
			if (i != j)
			{
				swap_int(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}

	if (i != high)
	{
		swap_int(&array[i], &array[high]);
		print_array(array, size);
	}

	return (i);
}

/**
 * quick_sort_recursive - recursive helper for quick_sort
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: size of array (for printing)
 */
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
	size_t p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);

		if (p > 0)
			quick_sort_recursive(array, low, p - 1, size);
		quick_sort_recursive(array, p + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 *              using the Quick sort algorithm (Lomuto)
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
