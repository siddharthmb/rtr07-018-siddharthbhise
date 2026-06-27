#include <stdio.h>

int main(void)
{
	// variables
	char option;

	// code
	printf("\n\n");
	printf("Press 'Q' or 'q' to quit...\n");
	while (1)
	{
		option = getch();
		if (option == 'q' || option == 'Q')
		{
			break;
		}
		else
		{
			printf("%c ", option);
		}
	}

	printf("\n");
	return 0;
}