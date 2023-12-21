#include "sort.h"

/**
 * swap - swap to doubly linked list elements
 * @a: left element
 * @b: right element
 * Return: pointer to a element (actual)
 */

listint_t *swap(listint_t *a, listint_t *b)
{
	if (a->prev)
		(a->prev)->next = b;
	if ((b->next))
		(b->next)->prev = a;
	b->prev = a->prev;
	a->prev = b;
	a->next = b->next;
	b->next = a;
}

/**
 * insertion_sort_list - sorts list in ascending order
 * @list: a doubly linked list of integers to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *actual, *ba;

	if (!list || !(*list) || !(*list)->next)
		return;

	actual = (*list)->next;
	while (actual)
	{
		ba = actual;
		actual = actual->next;
		while (ba->prev && ba)
		{
			if (ba->n < ba->prev->n)
			{
				swap(ba->prev, ba);
				if (!ba->prev)
					*list = ba;
				print_list(*list);
			}
			else
				ba = ba->prev;
		}
	}
}
