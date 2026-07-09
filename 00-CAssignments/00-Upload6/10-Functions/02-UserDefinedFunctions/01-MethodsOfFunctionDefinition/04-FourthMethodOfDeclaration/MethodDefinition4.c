#include <stdio.h>

int main(int argc, char* argv[], char* envp[])
{
	// function declarations
	int addition(int, int);

	// variables
	int num1, num2, result;
	
	// code
	printf("Enter num1: ");
	scanf("%d", &num1);
	printf("Enter num2: ");
	scanf("%d", &num2);

	result = addition(num1, num2);
	printf("%d + %d = %d\n", num1, num2, result);

	return 0;
}

int addition(int a, int b)
{
	return a + b;
}