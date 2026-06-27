#include <stdio.h>

int main(void)
{
	// variables
	int i, j, k;

	// code
	printf("\n\n");
	i = 1;
	do
	{
		printf("----- i = %d -----\n", i);
		j = 3;
		do
		{
			printf("\tj = %d\n", j);
			k = 10;
			do
			{
				printf("\t\tk = %d\n", k);
				++k;

			} while (k <= 12);
			
			printf("\n");
			--j;

		} while (j > 0);

		printf("\n\n");
		++i;

	} while (i <= 3);

	printf("\n");
	return 0;
}