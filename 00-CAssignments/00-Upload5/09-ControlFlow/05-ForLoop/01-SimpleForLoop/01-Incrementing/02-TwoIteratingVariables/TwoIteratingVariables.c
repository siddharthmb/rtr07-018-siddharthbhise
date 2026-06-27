#include <stdio.h>

int main(void)
{
	// variables
	int i, j;

	// code
	printf("\n\n");
	printf("This program has comma operator in condition part of for-loop.\nDeliberately kept it! Consider warned!\n\n");
	for (i = 1, j = 10; i <= 10, j <= 100; ++i, j = j + 15)
	{
		printf("\ti = %2d, j = %2d\n", i, j);
	}

	printf("\n");
	return 0;
}