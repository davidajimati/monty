#include "monty.h"
/**
 * pop - function to remove element from stacks
 * @head: head pointer
 * Return: first element in stack
 *
 * Description: pop is same as removing a node of a linked list
*/

void pop(stack_t *head)
{
	int retval;

	if (head == NULL)
		exit(EXIT_FAILURE); /* Stack is empty*/

	/**
	 * remove the first element (node)
	 * move the head pointer to point to the next element in the stack
	*/
	retval = head->n;
	head = head->next;
	printf("%d\n", retval);
}
