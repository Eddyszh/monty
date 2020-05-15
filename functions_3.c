#include "monty.h"
/**
 * pchar - prints the char at the top of the stack, followed by a new line
 * @top: top of the stack
 * @line: line number
 */
void pchar(stack_t **top, unsigned int line)
{
	if (!top || !*top)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty", line);
		exit(EXIT_FAILURE);
	}
	if (isascii(var.holder))
		printf("%c\n", var.holder);
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range", line);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line
 * @top: top of the stack
 * @line: line number
 */
void pstr(stack_t **top, __attribute__((unused))unsigned int line)
{
	stack_t *str = *top;

	if (!top || !*top || var.holder == 0)
	{
		printf("\n");
		return;
	}
	while (str && str->n != 0 && isascii(str->n))
	{
		printf("%c", str->n);
		str = str->next;
	}
	printf("\n");
}

/**
 * rotl - rotates the stack to the top
 * @top: top of the stack
 * @line: line number
 */
void rotl(stack_t **top, __attribute__((unused))unsigned int line)
{
	stack_t *temp = *top;

	if (!top || !*top || !(*top)->next)
		return;
	while (temp->next)
		temp = temp->next;
	temp->next = *top;
	(*top)->prev = temp;
	*top = (*top)->next;
	(*top)->prev = NULL;
	temp->next->next = NULL;
}

/**
 * rotr - rotates the stack to the bottom
 * @top: top of the stack
 * @line: line number
 */
void rotr(stack_t **top, __attribute__((unused))unsigned int line)
{
	stack_t *temp = *top;

	if (!top || !*top || !(*top)->next)
		return;
	while (temp->next)
		temp = temp->next;
	temp->next = *top;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*top)->prev = temp;
	*top = temp;
}
