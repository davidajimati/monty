#include "monty.h"
/**
 * stringsplit - 
*/
char **stringsplit(char *buf)
{
	char **avcode, *token, *dlim = " \n";
	int i;

	avcode = malloc(sizeof(char *));
	if (avcode == NULL)
	{
		free(buf);
		return (NULL);
	}
	token = strtok(buf, dlim);
	avcode[0] = strdup(token);
	for(i = 0; token != NULL; i++)
	{
		avcode[i] = strdup(token);
		token = strtok(NULL, dlim);
	}
	avcode[i] = NULL;
	return (avcode);
}
