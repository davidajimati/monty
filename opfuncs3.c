#include "monty.h"

/**
 * sub - subtracts the top element of the stack from 
 * the second top element of the stack
 * @stack: pointer to address of top of stack
 * @line_number: current execution line number
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;   
	
	if (node == NULL || node->next == NULL)
	{
		
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	node->next->n -= node->n;
	*stack = (*stack)->next;
	free(node);
}

void op_div(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (node == NULL || node->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (node->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	node->next->n /= node->n;
	*stack = (*stack)->next;
	free(node);
}

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (node == NULL || node->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	node->next->n *= node->n;
	*stack = (*stack)->next;
	free(node);
}

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (node == NULL || node->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (node->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	node->next->n %= node->n;
	*stack = (*stack)->next;
	free(node);
}
