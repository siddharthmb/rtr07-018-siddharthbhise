#include <stdio.h>

int main(void)
{
	// variables
	int i;

	// code
	printf("\n\n");
	i = 100;
	printf("i = [ ");
	while (i >= 50)
	{
		printf(" %3d ", i);
		--i;
	}

	printf("]\n");

	printf("\n");
	return 0;
}