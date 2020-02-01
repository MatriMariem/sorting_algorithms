#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: address of head of the list
 */
void insertion_sort_list(listint_t **list)
{
listint_t *tmp;
if ((!list || !(*list)) || !(*list)->next)
	return;
tmp = *list;
while (tmp)
{
print_list(*list);
tmp = tmp->next;
}

}
