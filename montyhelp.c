#include "monty.h"
/**
 * stringsplit - 
*/
char **stringsplit(char *buf)
{
	char **avcode, *bufcpy, *token, *dlim = " \n";
	int i;

	avcode = malloc(sizeof(char *));
	if (avcode == NULL)
	{
		free(buf);
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	bufcpy = strdup(buf);
	token = strtok(bufcpy, dlim);
	if (token == NULL)
	{
		free(bufcpy);
		free(avcode);
		return (NULL);
	}
	for(i = 0; token != NULL; i++)
	{
		avcode[i] = strdup(token);
		token = strtok(NULL, dlim);
	}
	avcode[i] = NULL;
	free(bufcpy);
	return (avcode);
}

/**
 *
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
