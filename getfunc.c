

/**
 * getfunc - gets function while checking through operation codes
 * @s: 
 * Return: function that performs operation
*/
/*
int data;
void (*getfunc(char **avcode))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	int j, i = 0;
	char *code;

	while (ops[i].opcode != NULL)
	{
		j = 0;
		while (avcode[j] != NULL)
		{
			code = avcode[j];
			if (strcmp(ops[i].opcode, code) == 0 )
			{
				return(ops[i].f);
			}
			j++;
		}
		
		i++;
	}
} */