#include <stdio.h>

int main(void)
{
	// variables
	float f, pi = 3.14f;

	// code
	printf("\n\n");
	f = pi;
	while (f <= (pi * 10.0f))
	{
		printf("\t%2.2f\n", f);
		f = f + pi;
	}

	printf("\n");
	return 0;
}