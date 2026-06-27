#include <stdio.h>

int main(void)
{
	// variables
	int i;
	char option;

	// code
	printf("\n\n");
	printf("Printing numbers [1, 10]\n");
	printf("Press 'Q' or 'q' to exit...\n");
	for (i = 1; i <= 10; ++i)
	{
		printf("\t%2d\n", i);
		option = getch();
		if (option == 'Q' || option == 'q') break;
	}

	printf("\n");
	return 0;
}