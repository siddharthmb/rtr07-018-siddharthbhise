#include <stdio.h>

int main(void)
{
	// variables
	int i, j;

	// code
	printf("\n\n");
	printf("Outer loop gets us the even number in range [1, 5],\n");
	printf("Inner loop prints the table for that number...\n\n");
	i = 1;
	for (; i <= 5; ++i)
	{
		if (i % 2 == 0)
		{
			printf("Even number %d, printing its table\n\t", i);
			j = i;
			for (; j <= 12 * i; j = j + i)
			{
				printf(" %2d ", j);
			}
		}

		printf("\n\n");
	}

	printf("\n");
	return 0;
}