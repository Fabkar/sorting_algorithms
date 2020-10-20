#include "sort.h"
/**
* swap_nodes - functions to make a swap between tow nodes.
* @n_1: Pointer to first node.
* @n_2: Pointer to second node.
* Return: Nothing
*/
void swap_nodes(listint_t *n_1, listint_t *n_2)
{
	if (n_1->prev != NULL)
		n_1->prev->next = n_2;
	if (n_2->next != NULL)
		n_2->next->prev = n_1;
	n_1->next = n_2->next;
	n_2->prev = n_1->prev;
	n_1->prev = n_2;
	n_2->next = n_1;
}
/**
* insertion_sort_list - Function to sort nodes in a double linked list.
* @list: Pointer to linked list
* Return: Nothing.
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *tmp2;

	tmp = (*list)->next;
	while (tmp != NULL)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		while (tmp2 && tmp2->prev != NULL)
		{
			if (tmp2->prev->n > tmp2->n)
			{
				swap_nodes(tmp2->prev, tmp2);
				if (tmp2->prev == NULL)
					*list = tmp2;
				print_list((const listint_t *)*list);
			}
			else
				tmp2 = tmp2->prev;
		}
	}
}
