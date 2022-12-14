#include "monty.h"

/**
 * intiate - creates a ne stack using existing struct
 * Return: pointer to front(head) of stack
 *
 * Description: creates a stack
*/

stack_t *initiate(void)
{
	stack_t *node = malloc(sizeof(stack_t)); /* Initiate the stack <name: NODE> */

	if (node == NULL) /* Check if malloc fails */
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	return(node);
}
