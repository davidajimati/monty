#include "monty.h"

/**
 * 
*/

void push()
{
	stack_t *node;
	stack_t *head;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		return (NULL);
	node->n = 6;
	node->next = NULL;
	if (head == NULL)
		head = node;
	else
	{
		node->next = head;
		head = node;
	}
}