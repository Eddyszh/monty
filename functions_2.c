#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @top: top of the stack
 * @line: line number
 */
void add(stack_t ** top, unsigned int line)
{
	int sum;

	if (!top || !*top || !(*top)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		free_stack(top, line);
		exit(EXIT_FAILURE);
	}
	sum = var.holder;
	pop(top, line);
	sum += var.holder;
	pop(top, line);
	var.holder = sum;
	push(top, line);
}
