#include <stdio.h>

int main(void)
{
	// variables
	int i, j;

	// code
	printf("\n\n");
	i = 5, j = 15;
	do
	{
		printf("\ti = %2d, j = %2d\n", i, j);
		--i, --j;
	} while (i >= 0, j >= 0);

	printf("\n");
	return 0;
}