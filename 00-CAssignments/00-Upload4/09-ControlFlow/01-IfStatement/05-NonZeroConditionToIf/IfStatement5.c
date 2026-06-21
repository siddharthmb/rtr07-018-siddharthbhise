#include <stdio.h>

int main(void)
{
	// variables
	int a;

	// code
	printf("\n\n");
	a = -5;
	if (a)
	{
		printf("if-block 1: 'a' exists with value %d\n", a);
	}

	a = -a;
	if (a)
	{
		printf("if-block 2: 'a' exists with value %d\n", a);
	}

	a = !a;
	if (a)
	{
		printf("if-block 3: 'a' exists with value %d\n", a);
	}

	printf("'a' was processed with first -5, then '-a', then '!a', and subjected to 3 if blocks.\nCheck which it went through and which it went over!\n");

	printf("\n");
	return 0;
}