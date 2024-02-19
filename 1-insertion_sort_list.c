#include "sort.h"

/**
 * swap_pointer - exchange pointer assignment
 * @left: left node
 * @right: right node
 * Return: void
 */
void swap_pointer(listint_t *left, listint_t *right)
{
	if (right->next)
		right->next->prev = left;
	left->next = right->next;

	if (left->prev)
		left->prev->next = right;
	right->prev = left->prev;

	left->prev = right;
	right->next = left;
}

/**
 * swap_nodes - exchange memory assigned values
 * @left: ptr to left node
 * @right: ptr to right node
 * Return: void
 */
void swap_nodes(listint_t **left, listint_t **right)
{
	listint_t *temp;

	swap_pointer(*left, *right);
	temp = *left;
	*left = *right;
	*right = temp;
}

/**
 * insertion_sort_list - algorithm
 * @list: ptr to head of list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev, *tracker;

	if (!list || !(*list) || !(*list)->next)
		return;

	prev = *list;
	curr = prev->next;
	tracker = curr->next;

	if (prev->n == curr->n)
		return;

	while (TRUE)
	{
		while (prev && prev->n > curr->n)
		{
			swap_nodes(&prev, &curr);

			if (!prev->prev)
				*list = prev;

			print_list(*list);

			curr = prev;
			prev = prev->prev;
		}

		if (!tracker)
			break;

		curr = tracker;
		prev = curr->prev;
		tracker = tracker->next;
	}
}
