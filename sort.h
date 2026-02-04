#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element
 * @next: Pointer to the next element
 */
typedef struct listint_s
{
	int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Print a doubly linked list of integers */
void print_list(const listint_t *list);

/* Bubble sort for an array of integers */
void bubble_sort(int *array, size_t size);

/* Insertion sort for a doubly linked list */
void insertion_sort_list(listint_t **list);

#endif /* SORT_H */
