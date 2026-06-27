#include <stdio.h>

int main(void)
{
	// variables
	int i, j;

	// code
	printf("\n\n");
	i = 10, j = 100;
	do
	{
		printf("\ti = %2d, j = %3d\n", i, j);
		--i;
		j = j + 100;
	} while (i >= 0, j <= 1000);

	printf("\n");
	return 0;
}