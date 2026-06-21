#include <stdio.h>

int main(void)
{
	// variables
	int a, b, c;

	// code
	printf("\n\n");

	a = 123, b = 456, c = 789;
	if (a < b)
	{
		printf("a[%d] is less than b[%d]\n", a, b);
	}
	else
	{
		printf("a[%d] is greater than or equal to b[%d]\n", a, b);
	}

	if (b != c)
	{
		printf("b[%d] and c[%d] are not equal!\n", b, c);
	}
	else
	{
		printf("b[%d] and c[%d] are equal!\n", b, c);
	}

	printf("\n");
	return 0;
}