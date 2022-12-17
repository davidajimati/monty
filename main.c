#include "monty.h"

/**
 * main - main driver of code
 * @ac: argument count
 * @av: argument strings
 * Return: Always zero
*/

int main(int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_handle(av);
	return (0);
}
