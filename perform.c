#include "monty.h"

void perform(stack_t **head, unsigned int linenum, char *line)
{
        unsigned int i;
	char *cmd, *push_num;

        instruction_t opcmd[] = {
                {"pall", pall}, {"pint", _pint},
                {"pop", _pop}, {"swap", _swap},
		{"add", _add}, {"nop", _nop},
		{"sub", _sub}, {"div", _div},
		{"mul", _mul}, {NULL, NULL}
        };

	cmd = strtok(line, DELIM);
	if (cmd == NULL)
		return;

	if (strcmp(cmd, "push") == 0)
        {
		push_num = strtok(NULL, DELIM);
		_push(head, linenum, atoi(push_num));
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
}
