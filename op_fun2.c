#include "monty.h"

/**
 * _pop - remove node to the top of stack
 * @head: head of list
 * @linenum: line num of monty file
 */

void _pop(stack_t **head, unsigned int linenum)
{
	stack_t *vagabond;

	if (!head || !*head)
	{
		printf("L%d: can't pop an empty stack\n", linenum);
		exit(EXIT_FAILURE);
	}
	vagabond = *head;
	*head = vagabond->next;
	free(vagabond);
}

/**
 * _swap - swap the top two elements of stack
 * @head: head of list
 * @linenum: line num of monty file
 */

void _swap(stack_t **head, unsigned int linenum)
{
	stack_t *vagabond;

	if (!head)
		return;

	if ((*head)->next == NULL || (*head)->next->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", linenum);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	vagabond = (*head)->next;

	(*head)->next = vagabond->next;
	vagabond->next = *head;
	vagabond->prev = NULL;
	(*head)->prev = vagabond;

	*head = vagabond;
}

/**
 * _add - add the top two elements of stack
 * @head: head of list
 * @linenum: line num of monty file
 */

void _add(stack_t **head, unsigned int linenum)
{
	stack_t *vagabond;

	if (!*head || !(*head)->next)
	{
		printf("L%d: can't add, stack too short\n", linenum);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	vagabond = (*head)->next;

	vagabond->n += (*head)->n;
	free(*head);
	*head = vagabond;
}
