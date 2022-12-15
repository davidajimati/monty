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
		/* free(buf); */
		return (NULL);
	}
	bufcpy = strdup(buf);
	token = strtok(bufcpy, dlim);
	if (token == NULL)
	{
		avcode[0] = NULL;
		/* free(bufcpy);
		free(avcode); */
		return (NULL);
	}
	for(i = 0; token != NULL; i++)
	{
		avcode[i] = strdup(token);
		token = strtok(NULL, dlim);
	}
	avcode[i] = NULL;
	/* free(buf);
	free(bufcpy); */
	return (avcode);
}
