#include "monty.h"

/**
 * file_handle - handle file passed as argument
 * @ac: argument count
 * @av: argument strings
*/

void file_handle(char **av)
{
	FILE *line;
	char *buf = NULL, *file, **avcode;
	size_t size;
	int line_no = 0;
	ssize_t nread;
	stack_t *stack = NULL;
	void (*func)(stack_t **, unsigned int);


	file = av[1];
	line = fopen(file, "r");
	if (line == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	nread = getline(&buf, &size, line);
	while (nread >= 0)
	{
		line_no++;
		avcode = stringsplit(buf);
		if (avcode == NULL)
		{
			nread = getline(&buf, &size, line);
			continue;
		}
		func = getfunc(avcode);
		if (func != NULL)
			func(&stack, line_no);
		free_av(avcode);
		nread = getline(&buf, &size, line);
	}
	free(buf);
	buf == NULL;
	fclose(line);
	free_stack(stack);
}
