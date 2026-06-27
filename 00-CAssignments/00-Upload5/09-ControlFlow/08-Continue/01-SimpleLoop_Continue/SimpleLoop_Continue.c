#include <stdio.h>

int main(void)
{
	// variables
	int i;

	// code
	printf("\n\n");
	printf("Printing Odd Numbers from 0 to 50\n");
	for (i = 0; i <= 50; ++i)
	{
		if (i % 2 == 0)
		{
			continue;
		}

		printf("\t%2d\n", i);
	}

	printf("\n");
	return 0;
}