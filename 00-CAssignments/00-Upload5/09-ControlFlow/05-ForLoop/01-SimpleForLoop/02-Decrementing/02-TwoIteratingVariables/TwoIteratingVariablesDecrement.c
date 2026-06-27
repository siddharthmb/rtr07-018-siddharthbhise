#include <stdio.h>

int main(void)
{
	// variables
	int i, j;

	// code
	printf("\n\n");
	for (i = 20, j = 100; i >= 1, j >= 5; --i, j = j - 5)
	{
		printf("\ti = %2d, j = %2d\n", i, j);
	}

	printf("\n");
	return 0;
}