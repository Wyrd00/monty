#include "monty.h"

/**
 * new_node - create new node
 * @head: head of list
 * @n: value of node
 * Return: new node
 */

stack_t *new_node(stack_t **head, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		printf("Error creating new node");
		free_list(*head);
		return (NULL);
	}
	new->n = n;
	new->prev = NULL;

	if (head != NULL)
		new->next = *head;
	*head = new;
	return (new);
}

/**
 * free_list - free linked list
 * @head: head of list
 */

void free_list(stack_t *head)
{
	stack_t *vagabond;

	while (head != NULL)
	{
		vagabond = head->next;
		free(head);
		head = vagabond;
	}
}
