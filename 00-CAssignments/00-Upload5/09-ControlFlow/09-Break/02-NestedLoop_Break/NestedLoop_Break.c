#include <stdio.h>

int main(void)
{
	// variables
	int i, j;

	// code
	printf("\n\n");

	i = 1;
	for (; i <= 10; ++i)
	{
		for (j = 1; j <= 10; ++j)
		{
			if (j > i)
			{
				break;
			}

			printf("\t* ");
		}

		printf("\n");
	}

	printf("\n");
	return 0;
}