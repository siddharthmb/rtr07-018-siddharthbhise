#include <stdio.h>

int main(void)
{
	// function prototypes
	int addition(int, int);

	// variable declarations
	int r, num1, num2, num3, num4;

	// code
	num1 = 10;
	num2 = 20;
	num3 = 30;
	num4 = 40;

	r = addition(addition(num1, num2), addition(num3, num4));

	printf("\n\n");
	printf("%d + %d + %d + %d = %d\n", num1, num2, num3, num4, r);

	return 0;
}

int addition(int a, int b)
{
	return a + b;
}
