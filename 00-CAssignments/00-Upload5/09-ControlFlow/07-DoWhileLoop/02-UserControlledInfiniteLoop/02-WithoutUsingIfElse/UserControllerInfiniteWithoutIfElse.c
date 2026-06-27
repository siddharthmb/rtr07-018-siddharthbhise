#include <stdio.h>

int main(void)
{
	// variables
	char option;

	// code
	printf("\n\n");
	printf("Press 'Q' or 'q' to quit...\n");
	do
	{
		option = getch();
		if (option != 'q' && option != 'Q')
		{
			printf(" %c ", option);
		}

	} while (option != 'Q' && option != 'q');
	
	printf("\n");
	return 0;
}