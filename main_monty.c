#include "monty.h"

/**
 * main - tests the codes
 * Return: 0
*/

int main(void)
{
	stack_t *head = initiate();

	push(head, 3);
	push(head, 5);
	push(head, 65);
	pall(head);
	return(0);
}
