#include <stdio.h>

int main(void)
{
	// variables
	float f, pi = 3.14f;

	// code
	printf("\n\n");
	f = pi;
	do
	{
		printf("\t%2.2f\n", f);
		f = f + pi;
	} while (f <= 10.0 * pi);

	printf("\n");
	return 0;
}