#include "lists.h"

/**
* check_cycle - checks if alinked list has a cycle
* @list: pointer to a linked list
*
* Return: 0 if false or 1 if true
**/
int check_cycle(listint_t *list)
{
	listint_t *tortuga = list;
	listint_t *rabbit = list;

	if (!list)
		return (0);
	while (tortuga->next && rabbit->next->next)
		{
		tortuga = tortuga->next;
		rabbit = rabbit->next->next;
		if (tortuga == rabbit)
			return (1);
	}
		return (0);
}
