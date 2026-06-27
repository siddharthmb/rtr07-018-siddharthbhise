#include <stdio.h>

int main(void)
{
	// variables
	char option;

	// code
	printf("\n\n");
	printf("Enter Q or q to quit...\n");
	do
	{
		option = getch();
		if (option == 'Q' || option == 'q')
		{
			break;
		}
		else
		{
			printf(" %c ", option);
		}
	} while (1);

	printf("\n");
	return 0;
}