#include <stdio.h>

int main(void)
{
	// variables
	int a, b, c;

	// code
	a = 9, b = 81, c = 81;
	printf("\n\n");
	if (a < b)
	{
		printf("Entered the first if-block after check of a[%d] < b[%d], got satisfied\n", a, b);
	}
	else
	{
		printf("Entered the else block, since a[%d] turned out to be >= b[%d]\n", a, b);
	}

	printf("\n");

	if (b != c)
	{
		printf("Entered second if-block because b[%d] != c[%d]\n", b, c);
	}
	else
	{
		printf("Entered the else part of the second if-block, because b[%d] == c[%d]\n", b, c);
	}

	printf("\n");
	return 0;
}