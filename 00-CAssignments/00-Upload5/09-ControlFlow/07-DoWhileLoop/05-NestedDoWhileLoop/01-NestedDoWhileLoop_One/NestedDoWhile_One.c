#include <stdio.h>

int main(void)
{
	// variables
	int i, j;

	// code
	printf("\n\n");
	i = 1;
	do
	{
		printf("----- i = %2d -----\n", i);
		j = 3;
		printf("\tj = ");
		do
		{
			printf("%d ", j);
			--j;
		} while (j > 0);

		printf("\n\n");
		++i;

	} while (i <= 3);

	printf("\n");
	return 0;
}