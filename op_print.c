#include "monty.h"

/**
 * pall - print content of list
 * @head: head of list
 * @linenum: line num of monty file
 */

void pall(stack_t **head, unsigned int linenum)
{
	stack_t *vagabond;

	if (!head || !*head)
	{
		printf("L%d: error with pall\n", linenum);
		exit(EXIT_FAILURE);
	}

	vagabond = *head;
	while (!vagabond)
	{
		printf("%d\n", vagabond->n);
		vagabond = vagabond->next;
	}
}

/**
 * _pint - print value at top of stack
 * @head: head of list
 * @linenum: line num of monty file
 */

void _pint(stack_t **head, unsigned int linenum)
{
	stack_t *vagabond;

	if (!head || !*head)
	{
		printf("L%d: can't pint, stack empty\n", linenum);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	vagabond = *head;
	printf("%d\n", vagabond->n);
}
