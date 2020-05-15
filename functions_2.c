#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @top: top of the stack
 * @line: line number
 */
void add(stack_t **top, unsigned int line)
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

/**
 * sub - subtracts the top element of the stack from the second top element
 * @top: top of the stack
 * @line: line number
 */
void sub(stack_t **top, unsigned int line)
{
	int subs;

	if (!top || !*top || !(*top)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		free_stack(top, line);
		exit(EXIT_FAILURE);
	}
	subs = var.holder;
	pop(top, line);
	subs = var.holder - subs;
	pop(top, line);
	var.holder = subs;
	push(top, line);
}

/**
 * div - divides the second top element of the stack by the top element
 * @top: top of the stack
 * @line: line number
 */
void _div(stack_t **top, unsigned int line)
{
	int divi;

	if (!top || !*top || !(*top)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		free_stack(top, line);
		exit(EXIT_FAILURE);
	}
	if (var.holder == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		free_stack(top, line);
		exit(EXIT_FAILURE);
	}
	divi = var.holder;
	pop(top, line);
	divi = var.holder / divi;
	pop(top, line);
	var.holder = divi;
	push(top, line);
}

/**
 * mul - multiplies the second top element of the stack with the top element
 * @top: top of the stack
 * @line: line number
 */
void mul(stack_t **top, unsigned int line)
{
	int mult;

	if (!top || !*top || !(*top)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		free_stack(top, line);
		exit(EXIT_FAILURE);
	}
	mult = var.holder;
	pop(top, line);
	mult *= var.holder;
	pop(top, line);
	var.holder = mult;
	push(top, line);
}

/**
 * mod - computes the rest of the division of the second
 * top element of the stack by the top element
 * @top: top of the stack
 * @line: line number
 */
void mod(stack_t **top, unsigned int line)
{
	int rem;

	if (!top || !*top || !(*top)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
		free_stack(top, line);
		exit(EXIT_FAILURE);
	}
	if (var.holder == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		free_stack(top, line);
		exit(EXIT_FAILURE);
	}
	rem = var.holder;
	pop(top, line);
	rem = var.holder % rem;
	pop(top, line);
	var.holder = rem;
	push(top, line);
}
