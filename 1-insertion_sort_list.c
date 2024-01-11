#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the list to sort
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		while (current->prev != NULL && current->n < current->prev->n)
		{
			temp = current;
			if (current->next != NULL)
				current->next->prev = temp->prev;
			current->prev->next = temp->next;
			current = current->prev;
			temp->prev = current->prev;
			if (current->prev != NULL)
				current->prev->next = temp;
			else
				*list = temp;
			current->prev = temp;
			temp->next = current;
			print_list(*list);
		}
		current = current->next;
	}
}
