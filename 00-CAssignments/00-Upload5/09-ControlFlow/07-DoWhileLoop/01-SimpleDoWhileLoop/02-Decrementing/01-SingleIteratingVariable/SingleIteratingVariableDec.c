#include <stdio.h>

int main(void)
{
	// variables
	int i;

	// code
	printf("\n\n");
	i = 10;
	do
	{
		printf("\t%2d\n", i);
		--i;
	} while (i >= 0);

	printf("\n");
	return 0;
}