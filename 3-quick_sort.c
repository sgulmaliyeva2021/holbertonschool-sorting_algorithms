#include "sort.h"
#include <stdio.h>

/**
 * swap_int - swaps two integers
 * @a: first integer pointer
 * @b: second integer pointer
 */
void swap_int(int *a, int *b)
{
    int tmp;

    if (a == b || !a || !b) /* Safety check to avoid overwriting same element */
        return;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * lomuto_partition - partitions an array using Lomuto scheme
 * @array: array of integers
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 * Return: pivot index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low, j;

    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
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

    return i;
}

/**
 * quick_sort_recursive - recursively sorts array using Quick sort
 * @array: array of integers
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    int pivot_index;

    if (low < high)
    {
        pivot_index = lomuto_partition(array, low, high, size);
        quick_sort_recursive(array, low, pivot_index - 1, size);
        quick_sort_recursive(array, pivot_index + 1, high, size);
    }
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm (Lomuto)
 * @array: array of integers
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quick_sort_recursive(array, 0, (int)size - 1, size);
}
