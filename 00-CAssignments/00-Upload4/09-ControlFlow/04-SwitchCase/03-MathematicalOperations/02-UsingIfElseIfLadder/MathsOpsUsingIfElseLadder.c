#include <stdio.h>

int main(void)
{
	// variables
	int a, b, result;
	char option, option_division;

	// code
	printf("\n\n");
	printf("Enter a: ");
	scanf("%d", &a);
	printf("Enter b: ");
	scanf("%d", &b);

	printf("Enter option as described below\n");
	printf("'+' for addition,\n");
	printf("'-' for subtraction,\n");
	printf("'*' for multiplication,\n");
	printf("'/' for division\n");

	printf("Enter option: ");
	option = getch();
	if (option == '+')
	{
		result = a + b;
		printf("a[%d] + b[%d] = %d\n", a, b, result);
	}
	else if (option == '-')
	{
		result = a - b;
		printf("a[%d] - b[%d] = %d\n", a, b, result);
	}
	else if (option == '*')
	{
		result = a * b;
		printf("a[%d] * b[%d] = %d\n", a, b, result);
	}
	else if (option == '/')
	{
		printf("Enter '/' for getting the quotient,\n");
		printf("Enter '%%' for getting the remainder: ");
		option_division = getch();
		if (b == 0)
		{
			printf("Denominator cannot be 0, making it 1\n");
			b = 1;
		}
		if (option_division == '/')
		{
			result = a / b;
			printf("a[%d] / b[%d] = %d\n", a, b, result);
		}
		else if (option_division == '%')
		{
			result = a % b;
			printf("a[%d] % b[%d] = %d\n", a, b, result);
		}
		else
		{
			printf("Invalid option %c for division\n", option_division);
		}
	}
	else
	{
		printf("Invalid option %c\n", option);
	}

	printf("\n");
	return 0;
}