#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - Delete node at a given index in a dlist
 * @head: Address of pointer to head node
 * @index: Index of node to delete (0-based)
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *node;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	node = *head;

	/* Avancer jusqu'au node à supprimer */
	for (i = 0; node != NULL && i < index; i++)
		node = node->next;

	/* Index hors borne */
	if (node == NULL)
		return (-1);

	/* Suppression tête */
	if (node->prev == NULL)
	{
		*head = node->next;
		if (node->next != NULL)
			node->next->prev = NULL;
		free(node);
		return (1);
	}

	/* Suppression milieu / fin */
	if (node->prev != NULL)
		node->prev->next = node->next;

	if (node->next != NULL)
		node->next->prev = node->prev;

	free(node);
	return (1);
}
