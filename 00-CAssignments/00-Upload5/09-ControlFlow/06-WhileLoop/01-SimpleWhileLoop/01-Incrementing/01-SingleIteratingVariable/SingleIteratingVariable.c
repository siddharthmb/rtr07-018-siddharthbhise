#include <stdio.h>

int main(void)
{
	// variables
	int i;

	// code
	printf("\n\n");
	i = 15;
	while (i >= 0)
	{
		printf("\t%2d\n", i);
		--i;
	}

	printf("\n");
	return 0;
}