#include "monty.h"

/**
 * getfunc - gets function while checking through operation codes
 * @s: 
 * Return: function that performs operation
*/
int data;

void (*getfunc(char **avcode))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	int j, i = 0;
	char *code, *element;

	while (ops[i].opcode != NULL)
	{
		j = 0;
		printf("op: %s\n", ops[i].opcode);
		while (avcode[j] != NULL)
		{
			code = avcode[j];
			data = atoi(avcode[j + 1]);
			if (strcmp(ops[i].opcode, code) == 0 )
			{
				printf("yel\n");
				return(ops[i].f);
			}
			j++;
		}
		
		i++;
	}
	printf("yel\n");
}

/**
 * push - adds an element to a *stack
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	node = malloc(sizeof (stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->prev = NULL;
	node->n = data;
	printf("nn: %d\n", node->n);
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

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}