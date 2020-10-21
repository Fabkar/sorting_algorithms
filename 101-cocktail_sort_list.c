#include "sort.h"
/**
* swap_nodes - swap in next for sorts a doubly linked list.
* @n_1: First Node.
* @n_2: Second Node.
* Return: Nothing.
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
 * swap_next  - swap the next node
 * @list: array by elements to list
 * Return: pointer to head
 */
listint_t *swap_next(listint_t **list)
{
	listint_t *tmp, *head = *list;

	while (head->next)
	{
		if (head->next->n < head->n)
		{
			tmp = head->next;
			swap_nodes(head, tmp);
			if (!(tmp->prev))
			{
				*list = tmp;
				head = tmp;
				break;
			}
		print_list(*list);
		}
		else
			head = head->next;
	}
	return (head);
}
/**
 * cocktail_sort_list - sort list next and prev
 * @list: list by elements to sort
 */
void cocktail_sort_list(listint_t **list)
{
	int flag = 0;
	listint_t *tmp, *head;

	if (!(*list) && !(list))
		return;
	head = *list;
	while (flag == 0)
	{
		head = swap_next(&head);
		if (!(head->prev))
		*list = head, print_list(*list);
		flag = 1;
		while (head->prev)
		{
			if (head->n < head->prev->n)
			{
				flag = 0;
				tmp = head->prev;
				swap_nodes(tmp, head);
				if (!(head->prev))
					*list = head;
				print_list(*list);
			}
			else
				head = head->prev;
		}
	}
}
