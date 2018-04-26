#ifndef MONTY
#define MONTY

#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#define DELIM " \n\t"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*Main functions*/
void perform(stack_t **head, unsigned int linenum, char *line);
void _push(stack_t **head, unsigned int linenum, int n);
void pall(stack_t **head, unsigned int linenum);
void _pint(stack_t **head, unsigned int linenum);
void _pop(stack_t **head, unsigned int linenum);
void _swap(stack_t **head, unsigned int linenum);
void _add(stack_t **head, unsigned int linenum);
void _nop(stack_t **head, unsigned int linenum);
void _sub(stack_t **head, unsigned int linenum);
void _div(stack_t **head, unsigned int linenum);
void _mul(stack_t **head, unsigned int linenum);
void _mod(stack_t **head, unsigned int linenum);

/*Helper functions*/
stack_t *new_node(stack_t **head, int n);
void free_list(stack_t *head);

#endif
