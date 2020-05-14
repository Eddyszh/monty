#include "monty.h"
/**
 * opcodes - executes the functions
 * @str: command received
 * @stack: pointer to stack
 * @line: line number
 */
void opcodes(char *str, stack_t **stack, unsigned int line)
{
	unsigned int i = 0;

	instruction_t opc[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	while (opc[i].opcode != NULL)
	{
		if (strcmp(str, opc[i].opcode) == 0)
		{
			opc[i].f(stack, line);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line, str);
	free_stack(stack, line);
	exit(EXIT_FAILURE);
}

/**
 * nop - doesn’t do anything
 * @top: top of the stack
 * @line: line number
 */
void nop(stack_t **top, unsigned int line)
{
	(void)top;
	(void)line;
}
