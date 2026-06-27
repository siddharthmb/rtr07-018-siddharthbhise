#include <stdio.h>

int main(void)
{
	// variables
	int i;

	// code
	printf("\n\n");
	i = 1;
	do
	{
		printf("\t%2d\n", i);
		++i;

	} while (i <= 10);

	printf("\n");
	return 0;
}