#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void file_handle(int ac, char **av);
void (*getfunc(char **avcode))(stack_t **, unsigned int);
char **stringsplit(char *buf);
int getdata(char *string);
//extern int data;
#endif