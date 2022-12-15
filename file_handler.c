#include "monty.h"

void file_handle(int ac, char **av)
{
	FILE *line;
	char *buf, *file, *token, **avcode;
	size_t size;
	int i = 0, line_no = 0;
	ssize_t nread;
	stack_t *stack = NULL;
	void (*func)(stack_t **, unsigned int);

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = av[1];
	line = fopen(file, "r");
	if (line == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(0);
	}
	nread = getline(&buf, &size, line);
	for (i = 0; nread >= 0; i++)
	{
		line_no++;
		printf("ln: %d \n", line_no);
		avcode = stringsplit(buf);
		if (avcode == NULL)
		{
			nread = getline(&buf, &size, line);
			continue;
		}
		func = getfunc(avcode);
		if (func != NULL)
			func(&stack, line_no);
		nread = getline(&buf, &size, line);
	}		
		
	fclose(line);
}