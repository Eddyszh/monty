#include "monty.h"
/**
 * push - pushes an element to the stack
 * @top: top of the stack
 * @line: line number
 */
void push(stack_t **top, unsigned int line)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!top)
	{
		fprintf(stderr, "L%d: unknown stack\n", line);
		exit(EXIT_FAILURE);
	}
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(top, line);
		exit(EXIT_FAILURE);
	}
	new->n = var.holder;
	new->prev = NULL;
	new->next = *top;
	if (*top != NULL)
		(*top)->prev = new;
	*top = new;
}

/**
 * pall - prints all the values on the stack
 * @top: top of the stack
 * @line: line number
 */
void pall(stack_t **top, unsigned int line)
{
	stack_t *print;

	if (!top)
	{
		fprintf(stderr, "L%d: invalid stack\n", line);
		exit(EXIT_FAILURE);
	}
	print = *top;
	while (print)
	{
		printf("%d\n", print->n);
		print = print->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @top: top of the stack
 * @line: line number
 */
void pint(stack_t **top, unsigned int line)
{
	if (!top || !*top)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*top)->n);
	}
}

/**
 * pop - removes the top element of the stack
 * @top: top of the atack
 * @line: linenumber
 */
void pop(stack_t **top, unsigned int line)
{
	if (!top || !*top)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	if ((*top)->next != NULL)
	{
		*top = (*top)->next;
		var.holder = (*top)->n;
		free((*top)->prev);
		(*top)->prev = NULL;
	}
	else
	{
		free(*top);
		*top = NULL;
	}
}

/**
 * swap - swaps the top two elements of the stack
 * @top: top of the stack
 * @line: line number
 */
void swap(stack_t **top, unsigned int line)
{
	int temp;

	if (!top || !*top || !(*top)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		free_stack(top, line);
		exit(EXIT_FAILURE);
	}
	temp = (*top)->n;
	(*top)->n = (*top)->next->n;
	(*top)->next->n = temp;
}
