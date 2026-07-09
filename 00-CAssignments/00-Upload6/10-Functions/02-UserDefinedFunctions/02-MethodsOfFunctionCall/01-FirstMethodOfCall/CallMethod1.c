#include <stdio.h>

int main(void)
{
	// function declarations
	void addition(void);
	int subtraction(void);
	void multiplication(int, int);
	int division(int, int);

	// variables
	int result_subtraction;
	int result_division;
	int num1, num2;

	// code
	printf("\n\n");

	addition();

	result_subtraction = subtraction();
	printf("subtraction op result = %d\n\n", result_subtraction);

	printf("Enter num1: ");
	scanf("%d", &num1);
	printf("Enter num2: ");
	scanf("%d", &num2);
	multiplication(num1, num2);

	printf("integer division op parameterised [%d / %d] = %d\n", num1, num2, division(num1, num2));

	return 0;
}

int division(int a, int b)
{
	if (b == 0) return EOF;

	return a / b;
}

void multiplication(int a, int b)
{
	printf("multiplication op parameterised [%d * %d] = %d\n", a, b, a * b);
}

int subtraction(void)
{
	// variables
	int num1, num2;
	// code
	printf("Enter num 1: ");
	scanf("%d", &num1);
	printf("Enter num 2: ");
	scanf("%d", &num2);

	return num1 - num2;
}

void addition()
{
	// variables
	int num1, num2;
	// code
	printf("Enter num 1: ");
	scanf("%d", &num1);
	printf("Enter num 2: ");
	scanf("%d", &num2);
	printf("%3d + %3d = %3d\n", num1, num2, num1 + num2);
}