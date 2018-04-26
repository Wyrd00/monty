#include "monty.h"

/**
 * _push - push a new node to the top of stack
 * @head: head of list
 * @n: value of new node
 */

void _push(stack_t **head, unsigned int linenum, int n)
{
	stack_t *new;

	if (!head)
	{
		printf("L%d: Error with stack\n", linenum);
		exit(EXIT_FAILURE);
	}
	new = new_node(head, n);
	if (!new)
	{
		printf("Error: cannot create new node\n");
		exit(EXIT_FAILURE);
	}
}

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
 * _nop - do nothing
 * @head: head of list
 * @linenum: line num of monty file
 */

void _nop(stack_t **head, unsigned int linenum)
{
	(void)*head;
	(void)linenum;
}
