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
		free(load.buf);
		free_stack(*stack);
		fclose(load.file);
		exit(EXIT_FAILURE);
	}
	node->next->n -= node->n;
	*stack = (*stack)->next;
	free(node);
}

/**
 * op_div - divides the second top element of the stack with
 * the top element of the stack
 * @stack: pointer to address of top of stack
 * @line_number: current execution line number
 */

void op_div(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (node == NULL || node->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free(load.buf);
		free_stack(*stack);
		fclose(load.file);
		exit(EXIT_FAILURE);
	}
	if (node->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*stack);
		free(load.buf);
		fclose(load.file);
		exit(EXIT_FAILURE);
	}
	node->next->n /= node->n;
	*stack = (*stack)->next;
	free(node);
}

/**
 * mul - multiplies the top element of the stack with
 * the second top element of the stack
 * @stack: pointer to address of top of stack
 * @line_number: current execution line number
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (node == NULL || node->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(load.buf);
		free_stack(*stack);
		fclose(load.file);
		exit(EXIT_FAILURE);
	}
	node->next->n *= node->n;
	*stack = (*stack)->next;
	free(node);
}

/**
 * mod - computes the rest of the division of
 * the second top element of the stack by the top element of the stack.
 * @stack: pointer to address of top of stack
 * @line_number: current execution line number
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (node == NULL || node->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free(load.buf);
		free_stack(*stack);
		fclose(load.file);
		exit(EXIT_FAILURE);
	}
	if (node->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(load.buf);
		free_stack(*stack);
		fclose(load.file);
		exit(EXIT_FAILURE);
	}
	node->next->n %= node->n;
	*stack = (*stack)->next;
	free(node);
}
