#include <stdio.h>

int main(void)
{
	// variables
	char option, ch = '\0';

	// code
	printf("\n\n");
	printf("Press 'Q' or 'q' to quit the infinite loop...");
	for (;;)
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

	printf("\n\n");
	printf("Bye!");
	printf("\n");
	return 0;
}