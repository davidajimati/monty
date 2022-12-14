#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "test.h"

int main()
{
	char **av, *tok, s[] = "hey/hi/jk";
	int i;

	tok = strtok(s, "/");
	av = malloc(sizeof(char *));
	for (i = 0; tok != NULL; i++)
	{
		av[i] = strdup(tok);
		tok = strtok(NULL, "/");
	}
	av[i] = NULL;
	for (i = 0; av[i]; i++)
	{
		printf("av: %s\n", av[i]);
	}
	//increment();
	use();
	printf("n: %d\n", num);
	return (0);
}