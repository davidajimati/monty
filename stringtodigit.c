#include "monty.h"
/**
 * digit - checks if a string contains only digits
 * @s: string
 * Return: 1 if digit otherwise 0
*/
int digit(char *s)
{
	int flag = 0;
	char *str = s;

	if (str == NULL)
	{
		return (0);
	}
	while (*str)
	{
		if (!isdigit(*str++))
		{
			break;
		}

		flag = 1;
	}
	if (flag)
	{
		load.data = atoi(s);
		return (1);
	}
	return (0);
}
