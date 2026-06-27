#include <stdio.h>

int main(void)
{
	// variables
	int i, j;

	// code
	printf("\n\n");
	i = 1, j = 100;
	while (i <= 10, j <= 1000)
	{
		printf("\ti = %2d, j = %3d\n", i, j);
		++i;
		j = j + 100;
	}

	printf("\n");
	return 0;
}