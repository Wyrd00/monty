#include "monty.h"

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

/**
 * _sub - subtract the top two elements of stack
 * @head: head of list
 * @linenum: line num of monty file
 */

void _sub(stack_t **head, unsigned int linenum)
{
	stack_t *vagabond;

	if (!*head || !(*head)->next)
	{
		printf("L%d: can't sub, stack too short\n", linenum);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	vagabond = (*head)->next;

	vagabond->n -= (*head)->n;
	free(*head);
	*head = vagabond;
}

/**
 * _div - divide the top two elements of stack
 * @head: head of list
 * @linenum: line num of monty file
 */

void _div(stack_t **head, unsigned int linenum)
{
	stack_t *vagabond;

	if (!*head || !(*head)->next)
	{
		printf("L%d: can't div, stack too short\n", linenum);
		free_list(*head);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		printf("L%d: division by zero\n", linenum);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	vagabond = (*head)->next;

	vagabond->n /= (*head)->n;
	free(*head);
	*head = vagabond;
}

/**
 * _mul - multiply the top two elements of stack
 * @head: head of list
 * @linenum: line num of monty file
 */

void _mul(stack_t **head, unsigned int linenum)
{
	stack_t *vagabond;

	if (!(*head) || !(*head)->next)
	{
		printf("L%d: can't mul, stack too short\n", linenum);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	vagabond = (*head)->next;

	vagabond->n *= (*head)->n;
	free(*head);
	*head = vagabond;
}
