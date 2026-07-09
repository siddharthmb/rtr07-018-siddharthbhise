#include <stdio.h>

int main(void)
{
	void addition(void);

	addition();
	return 0;
}

void addition(void)
{
	// variable declaration
	int num1, num2;

	printf("Enter num 1: ");
	scanf("%d", &num1);
	printf("Enter num 2: ");
	scanf("%d", &num2);
	printf("%3d + %3d = %3d\n", num1, num2, (num1 + num2));
	printf("\n");
}