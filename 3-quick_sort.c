#include "sort.h"

/**
 * swap_int - swaps two integers in an array and prints the array
 * @a: pointer to first integer
 * @b: pointer to second integer
 * @array: the array
 * @size: size of the array
 */
void swap_int(int *a, int *b, int *array, size_t size)
{
	int temp;

	if (*a != *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
		print_array(array, size);
	}
}

/**
 * lomuto_partition - partitions array using Lomuto scheme
 * @array: the array
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 * Return: partition index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap_int(&array[i], &array[j], array, size);
		}
	}
	swap_int(&array[i + 1], &array[high], array, size);
	return (i + 1);
}

/**
 * quick_sort_recursive - recursive helper for quick sort
 * @array: the array
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pi - 1, size);
		quick_sort_recursive(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: the array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
