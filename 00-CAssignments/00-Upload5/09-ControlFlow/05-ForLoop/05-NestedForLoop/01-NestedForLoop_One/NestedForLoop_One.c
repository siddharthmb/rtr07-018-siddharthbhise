#include <stdio.h>

int main(void)
{
	// variables
	int i, j;

	// code
	printf("\n\n");
	for (i = 1; i <= 10; ++i)
	{
		printf("----i = %d----\n", i);
		printf("\tj = [ ");
		for (j = 5; j > 0; --j)
		{
			printf("%d ", j);
		}
		printf("]\n\n");
	}

	printf("\n");
	return 0;
}