#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - function that inserts a number into
 * a sorted singly linked list
 * @head: double pointer to the head node
 * @number: integer assigned to a node
 * Return: address (pointer) to the new node
 * or NULL if insertion failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current = NULL;
	listint_t *new_node = NULL;

	current = *head;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = number;
	new_node->next = NULL;

	if (current == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	if (current->n >= number)
	{
		new_node->next = current;
		*head = new_node;
		return (new_node);
	}
	if (current->next == NULL)
	{
		current->next = new_node;
		return (new_node);
	}
	while (current->next->n <= number)
	{
		current = current->next;
		if (current->next == NULL)
		{
			current->next = new_node;
			return (new_node);
		}
	}
	new_node->next = current->next;
	current->next = new_node;
	return (new_node);
}
