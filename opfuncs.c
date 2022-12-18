#include "monty.h"

/**
 * getfunc - gets corresponding function for specific operation codes
 * @avcode: array of strings of each line of code
 * Return: pointer to appropriate function
 */

void (*getfunc(char **avcode, stack_t **stack))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
	    {"push", push},
	    {"pall", pall},
	    {"pint", pint},
	    {"pop", pop},
	    {"nop", nop},
	    {"swap", swap},
	    {"add", add},
	    {"sub", sub},
	    {"div", op_div},
	    {"mul", mul},
	    {"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
	    {NULL, NULL}};
	int i = 0;
	char *code, *element;

	while (ops[i].opcode != NULL)
	{
		code = avcode[0];
		if (strcmp("push", code) == 0)
		{
			element = avcode[1];
			if (!digit(element))
			{
				fprintf(stderr, "L%d: usage: push integer\n", load.count);
				free_stack(*stack);
				free_av(avcode);
				fclose(load.file);
				exit(EXIT_FAILURE);
			}
		}

		if (strcmp(ops[i].opcode, code) == 0)
		{
			return (ops[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * push - adds an element to a stack
 * @stack: pointer to address of head node of a stack
 * @line_number: current line of execution
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	(void)line_number;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(load.buf);
		fclose(load.file);
		exit(EXIT_FAILURE);
	}
	node->prev = NULL;
	node->n = load.data;
	if (*stack == NULL)
	{
		*stack = node;
		node->next = NULL;
	}
	else
	{
		(*stack)->prev = node;
		node->next = *stack;
		*stack = node;
	}
}

/**
 * pall - prints all members of a stack
 * @stack: pointer to address of head node of a stack
 * @line_number: current line of execution
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	(void)line_number;

	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
