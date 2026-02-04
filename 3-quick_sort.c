#include "sort.h"

/**
 * swap_int - swaps two integers in an array
 * @a: first integer
 * @b: second integer
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
 * lomuto_partition - partitions the array using Lomuto scheme
 * @array: array to partition
 * @low: start index
 * @high: end index
 * @size: size of array (for printing)
 * Return: index of pivot
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low, j;

    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            if (i != j)  /* only swap if different index */
            {
                swap_int(&array[i], &array[j]);
                print_array(array, size);
            }
            i++;
        }
    }

    if (i != high)  /* final pivot swap */
    {
        swap_int(&array[i], &array[high]);
        print_array(array, size);
    }
    return i;
}

/**
 * quick_sort_recursive - recursive Quick sort
 * @array: array to sort
 * @low: start index
 * @high: end index
 * @size: array size for printing
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
 * quick_sort - sorts an array using Quick sort (Lomuto)
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}
