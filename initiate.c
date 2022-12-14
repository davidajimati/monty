#include "monty.h"
/**
 * push - function to add element to stack
 * @num: data to be inserted to stack
 * Return: Nothing
*/

void initiate(stack_t *head)
{
	if (head == NULL)
	{
		stack_t *node;
		stack_t *head;
		stack_t *prev;
		stack_t *next;

		node = malloc(sizeof(stack_t));
		head = node;
		next = node->next;
		prev = &node;

		if (node == NULL)
			exit(EXIT_FAILURE);
	}
}