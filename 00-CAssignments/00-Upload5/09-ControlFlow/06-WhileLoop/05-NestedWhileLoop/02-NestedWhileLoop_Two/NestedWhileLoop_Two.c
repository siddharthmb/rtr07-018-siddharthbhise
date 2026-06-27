#include <stdio.h>

int main(void)
{
	// variables
	int i, j, k;

	// code
	printf("\n\n");
	i = 1;
	while(i <= 3)
	{
		printf("----- i = %d -----\n", i);
		j = 1;
		while (j <= 3)
		{
			printf("\t--- j = %d ---\n", j);
			k = 1;
			while (k <= 3)
			{
				printf("\t\t- k = %d -\n", k);
				++k;
			}

			++j;
		}

		++i;
	}

	printf("\n");
	return 0;
}