#include <stdio.h>

int main(void)
{
	// function declarations
	int addition(int, int);

	// variable declarations
	int r, num1, num2;

	// code
	num1 = 10;
	num2 = 40;

	printf("\n\n");
	printf("%d + %d = %d\n", num1, num2, addition(num1, num2));

	return 0;
}

int addition(int a, int b)
{
	int _addition(int, int);

	return _addition(a, b);
}

int _addition(int a, int b)
{
	return a + b;
}
