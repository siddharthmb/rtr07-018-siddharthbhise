#include <stdio.h>

int main(void)
{
	// variables
	int i, j;

	// code
	printf("\n\n");
	i = 20, j = 30;
	while (i >= 1, j <= 50)
	{
		printf("\ti = %2d, j = %d\n", i, j);
		--i;
		++j;
	}

	printf("\n");
	return 0;
}