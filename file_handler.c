#define _POSIX_C_SOURCE 200809L
#include "monty.h"


/**
 * file_handle - handle file passed as argument
 * @ac: argument count
 * @av: argument strings
*/
load_t load = {NULL, NULL, 0};
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
	load.file = line;
	if (line == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	nread = getline(&buf, &size, line);
	load.buf = buf;
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
		free_av(avcode);
		if (func != NULL)
			func(&stack, line_no);
		nread = getline(&buf, &size, line);
	}
	free(buf);
	buf = NULL;
	fclose(line);
	free_stack(stack);
}
