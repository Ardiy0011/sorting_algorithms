#include "sort.h"

/**
 * insertion_sort_list - function sorts data in a linked list
 * @list: double pointer to the struct
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *tmp;

	if (!list)
	return;

	ptr = *list;

	while (ptr)
	{
	while (ptr->next && (ptr->n > ptr->next->n))
	{
	tmp = ptr->next;
	ptr->next = tmp->next;
	tmp->prev = ptr->prev;

	if (ptr->prev)
	ptr->prev->next = tmp;

	if (tmp->next)
	tmp->next->prev = ptr;

	ptr->prev = tmp;
	tmp->next = ptr;

	if (tmp->prev)
	ptr = tmp->prev;
	else
	*list = tmp;

	print_list(*list);
	}
	ptr = ptr->next;
	}
}


/**
 * freeing - frees temporary pointer created
 * @list: pointer to the pointer to struct
 */
void freeing(listint_t *list) 
{
	listint_t *tmp;
	while (list != NULL)
	{
	tmp = list;
	list = list->next;
	free(tmp);
	}
}


/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
	listint_t *list;
	listint_t *node;
	int *tmp;

	list = NULL;
	while (size--)
	{
		node = malloc(sizeof(*node));
		if (!node)
		return (NULL);
		tmp = (int *)&node->n;
		*tmp = array[size];
		node->next = list;
		node->prev = NULL;
		list = node;
		if (list->next)
		list->next->prev = list;
	}
	return (list);
}
