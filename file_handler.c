#include "monty.h"

void file_handle(int ac, char **av)
{
	FILE *fileptr;
	char buf[256], *file;
	int ch;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = av[1];
	fileptr = fopen(file, "r");
	if (fileptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	ch = getc(fileptr);
	while (ch != EOF)
	{
		putchar(ch);
		ch = getc(fileptr);
	}

	/*fgets(buf, 256, fileptr);
	while (fgets(buf, 256, fileptr) != NULL)
	{
		printf("%s\n", buf);
	}*/
	fclose(fileptr);
}