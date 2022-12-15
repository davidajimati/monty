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

	checkstack(stack, line_number);
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
