#include "monty.h"

/**
 * getnumtokens - gets number of tokens passed
 * @buf: string
 * Return: number of tokens
*/

int getnumtokens(char *buf)
{
	int ntokens = 1;
	char *token, *dlim = " \n";

	token = strtok(buf, dlim);
	while (token != NULL)
	{
		ntokens++;
		token = strtok(NULL, dlim);
	}
	return (ntokens);
}

/**
 * stringsplit - splits a string into substrings
 * @buf: string
 * Return: pointer to address of substrings
*/

char **stringsplit(char *buf)
{
	char **avcode, *bufcpy, *token, *dlim = " \n";
	int i, ntokens;

	bufcpy = strdup(buf);
	ntokens = getnumtokens(buf);
	avcode = malloc(sizeof(char *) * ntokens);
	if (avcode == NULL)
	{
		free(buf);
		free(bufcpy);
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(bufcpy, dlim);
	if (token == NULL)
	{
		free(bufcpy);
		free(avcode);
		return (NULL);
	}
	for (i = 0; token != NULL; i++)
	{
		avcode[i] = strdup(token);
		token = strtok(NULL, dlim);
	}
	avcode[i] = NULL;
	free(bufcpy);
	return (avcode);
}

/**
 * free_av - frees memory used by array of strings
 * @av: array of strings
 */

void free_av(char **av)
{
	int i;

	for (i = 0; av[i]; i++)
	{
		free(av[i]);
	}
	free(av);
}

/**
 * free_stack - frees a linked list stack_t
 * @stack: pointer to head of linked list
*/

void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}
