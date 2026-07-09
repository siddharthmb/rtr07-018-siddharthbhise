#include <stdio.h>

int main(int argc, char* argv[], char* envp[])
{
	// function declaration
	void addition(int, int);

	// variables
	int a, b;

	// code
	printf("Enter num1: ");
	scanf("%d", &a);
	printf("Enter num2: ");
	scanf("%d", &b);

	addition(a, b);

	return 0;
}

void addition(int a, int b)
{
	printf("%3d + %3d = %3d\n\n", a, b, a + b);
}