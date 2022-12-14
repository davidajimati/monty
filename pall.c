#include "monty.h"

/**
 * pall - function to print all elements in stack
 * @head: pointer to first element in stack
 * Return: Nothing
 *
 * Description: pall traverses the lists and prints the data to stdout
*/

void pall(stack_t *head)
{
	int pr;

	if (head == NULL)
		exit (EXIT_FAILURE);

	pr = head->n;
	while (head != NULL)
	{
		printf("%d\n", pr);
		head = head->next;
	}
}
