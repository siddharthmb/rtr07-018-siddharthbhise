#include <stdio.h>

int main(void)
{
	// variables
	int i, j;

	// code
	printf("\n\n");
	i = 1;
	while (i <= 5)
	{
		printf("----- i = %d -----\n", i);
		j = 1;
		printf("\t j = ");
		while (j <= 3)
		{
			printf(" %d ", j);
			++j;
		}
		printf("\n");
		++i;
	}

	printf("\n");
	return 0;
}