#include "monty.h"

/**
 * sub - subtracts the top element of the stack from
 * the second top element of the stack
 * @stack: pointer to address of top of stack
 * @line_number: current execution line number
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	int targ;
	char targc;

	if (node == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(load.buf);
		free_stack(*stack);
		fclose(load.file);
		exit(EXIT_FAILURE);
	}

	targ = node->n;
	targc = targ;

	if (targ < 0 || targ > 127)
	{
		fprintf(stderr,"L%d: can't pchar, value out of range", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", targc);
}

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	(void) line_number;

	if (node == NULL)
	{
		putchar('\n');
		free(load.buf);
		free_stack(*stack);
		fclose(load.file);
		exit(EXIT_FAILURE);
	}

	while (node != NULL)
	{
		if (node->n == 0 || !node->n || node->n < 0 || node->n > 257)
			break;

		printf("%c", node->n);
		node = node->next;
	}
	putchar('\n');
}

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	stack_t *ptr = NULL;
	stack_t *ptr2 = NULL;
	(void)line_number;

	if (node == NULL || node == NULL)
		return;

	ptr = node;
	ptr2 = node->next;

	while (node->next != NULL)
	{
		ptr2 = ptr->next;
		ptr->prev = node->next;
		node = node->next;

	}
	free(load.buf);
	free_stack(*stack);
	fclose(load.file);
}

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	stack_t *ptr = NULL;
	(void)line_number;

	while (node != NULL)
	{
		ptr->prev = node->next;
		node = node->next;
		ptr = ptr->prev;
	}

	node = ptr;
	free(load.buf);
	free_stack(*stack);
	fclose(load.file);
}
