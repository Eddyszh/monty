#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct variables - variables to use as a global variables
 * @holder: stores an int value for some checks
 * @check: verifies if is a stack o queue
 *
 * Description: variables for global variable
 */
typedef struct variables
{
	int holder;
	char check;
} var_t;

extern var_t var;
var_t var;

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
 * struct instruction_s - opcode and its function
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

void _strtok(char *str, stack_t **stack, unsigned int line);
int _isdigit(char *str);
void free_stack(stack_t **stack, unsigned int line);
void opcodes(char *str, stack_t **stack, unsigned int line);
void push(stack_t **top, unsigned int line);
void pall(stack_t **top, unsigned int line);
void pint(stack_t **top, unsigned int line);
void pop(stack_t **top, unsigned int line);
void swap(stack_t **top, unsigned int line);
void add(stack_t **top, unsigned int line);
void nop(stack_t **top, unsigned int line);
void sub(stack_t **top, unsigned int line);
void _div(stack_t **top, unsigned int line);
void mul(stack_t **top, unsigned int line);
void mod(stack_t **top, unsigned int line);
void pchar(stack_t **top, unsigned int line);
void pstr(stack_t **top, unsigned int line);
void rotl(stack_t **top, unsigned int line);
void rotr(stack_t **top, unsigned int line);

#endif
