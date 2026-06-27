#include <stdio.h>

int main(void)
{
	// variables
	float f, f_pi = 22.0f / 7.0f;

	// code
	printf("\n\n");
	for (f = f_pi; f <= (f_pi * 10.0f); f = f + f_pi)
	{
		printf("\tf = %2.2f\n", f);
	}

	printf("\n");
	return 0;
}