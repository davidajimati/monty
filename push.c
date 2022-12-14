#include "monty.h"
/**
 * push - function to add element to stack
 * @num: data to be inserted to stack
 * @head: head pointer
 * Return: Nothing
 *
 * Description: Adding an element to a stack is same as
 * adding a node to a linked list
*/

stack_t *push(stack_t *head, int num)
{
	stack_t *node = malloc(sizeof(stack_t));
	/**
	 * assign values to the beginning of stack;
	 * next points to where head formerly points
	 * head(top) now points to the new element
	*/
	node->n = num;
	node->next = head;
	head = node;
	return (node);

	free(node);
}
