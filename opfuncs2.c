#include "monty.h"

/**
 * pint - prints top element of stack
 * @stack: pointer to address of head of a stack
 * @line_number: current line of execution
*/

void pint(stack_t **stack, unsigned int line_number)
{
	checkstack(stack, line_number);
	printf("%d\n", (*stack)->n);
}

/**
 * pop - deletes top element of stack
 * @stack: pointer to address of head of a stack
 * @line_number: current line of execution
*/

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
	tmp = NULL;

}

/**
 * nop - does nothing
 * @stack: pointer to address of head of a stack
 * @line_number: current line of execution
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
}

/**
 * swap - swaps top 2 members of stack
 * @stack: pointer to address of head of a stack
 * @line_number: current line of execution
*/

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	int tmp;

	if (node == NULL || node->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	tmp = node->n;
	node->n = node->next->n;
	node->next->n = tmp;
}
