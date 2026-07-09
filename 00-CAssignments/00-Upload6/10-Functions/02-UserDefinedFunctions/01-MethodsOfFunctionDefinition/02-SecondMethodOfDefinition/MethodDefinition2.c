#include <stdio.h>

int main(void)
{
	// function declaration
	int addition(void);

	// variable declaration
	int result;
	result = addition();

	printf("\n\nResult = %3d\n", result);

	return 0;
}

int addition(void)
{
	// variable declarations
	int num1, num2;
	// code
	printf("\n\n");
	printf("Enter num 1: ");
	scanf("%d", &num1);
	printf("Enter num 2: ");
	scanf("%d", &num2);

	return (num1 + num2);
}