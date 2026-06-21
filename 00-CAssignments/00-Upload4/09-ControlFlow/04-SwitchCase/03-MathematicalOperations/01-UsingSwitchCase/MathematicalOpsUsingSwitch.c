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

	printf("Enter option as per below descriptions\n");
	printf("'+' for addition,\n");
	printf("'-' for subtraction,\n");
	printf("'*' for multiplication,\n");
	printf("'/' for division,\n");

	option = getch();
	switch (option)
	{
	case '+':
		result = a + b;
		printf("a[%d] + b[%d] = %d\n", a, b, result);
		break;
	case '-':
		result = (a > b) ? a - b : b - a;
		printf("a[%d] - b[%d] = %d\n", a, b, result);
		break;
	case '*':
		result = a * b;
		printf("a[%d] * b[%d] = %d\n", a, b, result);
		break;
	case '/':
		int _b = b;
		printf("Enter '/' for quotient upon division\nEnter '%%' for remainder upon division\n");
		option_division = getch();
		switch (option_division)
		{
		case '%':
			if (_b == 0)
			{
				printf("Denominator cannot be zero, making it 1!\n");
				_b = 1;
			}
			result = a / _b;
			printf("Result of a[%d] / b[%d] = %d\n", a, _b, result);
		case '/':
			result = a % _b;
			printf("Result of a[%d] %% b[%d] = %d\n", a, _b, result);
		default:
			printf("HAHA! Full-On Fall-Through happening here!\n");
			break;
		}
		break;
	default:
		printf("[Err] %c => Invalid option entered!\n", option);
		break;
	}

	printf("\n");
	return 0;
}