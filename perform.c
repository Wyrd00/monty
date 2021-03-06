#include "monty.h"

/**
 * perform - argv to check and execute opcodes
 * @head: linked list
 * @linenum: total lines in monty file
 * @line: line from monty file
 */

void perform(stack_t **head, unsigned int linenum, char *line)
{
	unsigned int i;
	char *cmd, *p_num;

	instruction_t opcmd[] = {
		{"pall", pall}, {"pint", _pint},
		{"pop", _pop}, {"swap", _swap},
		{"add", _add}, {"nop", _nop},
		{"sub", _sub}, {"div", _div},
		{"mul", _mul}, {"mod", _mod},
		{NULL, NULL}
	};

	cmd = strtok(line, DELIM);
	if (cmd == NULL || check_comment(cmd) == 1)/*if blank line or comment*/
		return;

	if (strcmp(cmd, "push") == 0)
	{
		p_num = strtok(NULL, DELIM);
		if (!p_num || (atoi(p_num) == 0 && strcmp(p_num, "0") != 0))
		{
			printf("L%d: usage: push integer\n", linenum);
			exit(EXIT_FAILURE);
		}
		_push(head, linenum, _atoi(p_num));
		return;
	}

	i = 0;
	while (opcmd[i].opcode)
	{
		if (strcmp(cmd, opcmd[i].opcode) == 0)
		{
			opcmd[i].f(head, linenum);
			return;
		}
		i++;
	}
	printf("L%d: unknown instruction %s\n", linenum, cmd);
	exit(EXIT_FAILURE);
}
