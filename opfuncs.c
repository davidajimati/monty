#include "monty.h"

/**
 * push - adds an element to a stack
*/
stack_t *head;
void push()
{
	int data;
	stack_t *node;

	node = malloc(sizeof (stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	printf("Enter the element: ");
	scanf("%d", &data);
	node->prev = NULL;
	node->n = data;
	if (head == NULL)
	{
		head = node;
		node->next = NULL;	
	}
	else
	{
		head->prev = node;
		node->next = head;
		head = node;
	}
}

void pall()
{
	stack_t *node = head;

	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}