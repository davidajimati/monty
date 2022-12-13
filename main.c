#include "monty.h"

/**
 *
*/
int main()
{
	int choice;
	

	while (choice != 3)
	{
		printf("Enter choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
				push();
				break;
			case 2:
				pall();
				break;
			default:
				exit(0);
		}
	}
	return (0);
}