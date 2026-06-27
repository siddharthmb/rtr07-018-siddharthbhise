#include <stdio.h>

int main(void)
{
	// variables
	int i, j, k;

	// code
	printf("\n\n");
	for (i = 1; i <= 10; ++i)
	{
		printf("----- i = %d -----\n", i);
		for (j = 5; j > 0; --j)
		{
			printf("\tj = %d\n", j);
			for (k = 1; k <= 3; ++k)
			{
				printf("\t\tk = %d\n", k);
			}
			printf("\n");
		}
		printf("\n\n");
	}

	printf("\n");
	return 0;
}