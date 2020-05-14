#include "monty.h"
/**
 * main - main function
 * @ac: arguments
 * @av: number of arguments
 * Return: Success
 */
int main(int ac, char **av)
{
	FILE *file;
	char *buf = NULL, *str;
	size_t bufzise = 0;
	unsigned int line_count = 1;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buf, &bufzise, file) != -1)
	{
		if (*buf != '\n')
		{
			str = strtok(buf, "\n");
			_strtok(str, &stack, line_count);
		}
		line_count++;
	}
	fclose(file);
	free(buf);
	if (stack != NULL)
		free_stack(&stack, line_count);
	return (EXIT_SUCCESS);
}

/**
 * _strtok - tokenizes the strings
 * @str: string passed
 * @stack: pointer to stack
 * @line: line number
 * Return: token
 */
void _strtok(char *str, stack_t **stack, unsigned int line)
{
	char *token, *tokens;

	token = strtok(str, " ");
	if (!token || *token == ' ' || *token == '\n')
		return;
	if (strcmp(token, "push") == 0)
	{
		tokens = token;
		token = strtok(NULL, " ");
		if (!_isdigit(token))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			free_stack(stack, line);
			exit(EXIT_FAILURE);
		}
		var.holder = atoi(token);
		opcodes(tokens, stack, line);
	}
	else
	{
		opcodes(token, stack, line);
	}
}

/**
 * _isdigit - verifies if the arg passed is a digit
 * @str: arg passed
 * Return: 1 if is digit, 0 otherwise
 */
int _isdigit(char *str)
{
	if (!str)
		return (0);
	if (*str == '-')
		str++;
	while (*str != '\0')
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	str++;
	return (1);
}

/**
 * free_stack - frees the stack
 * @stack: pointer to stack
 * @line: line number
 */
void free_stack(stack_t **stack, unsigned int line)
{
	if (!stack)
		return;
	while (*stack)
		pop(stack, line);
}
