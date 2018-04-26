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
		return;

	new = new_node(head, n);
	if (!new)
	{
		printf("L%d: error with push\n", linenum);
		/*free stuff*/
		free_list(*head);
		exit(EXIT_FAILURE);
	}
}

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
	while (vagabond != NULL)
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
		exit(EXIT_FAILURE);
	}
	vagabond = *head;

	if (*head)
		printf("%d\n", vagabond->n);
}
