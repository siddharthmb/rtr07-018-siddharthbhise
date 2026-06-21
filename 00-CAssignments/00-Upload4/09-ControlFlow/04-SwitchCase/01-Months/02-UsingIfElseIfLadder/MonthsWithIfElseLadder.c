#include <stdio.h>

int main(void)
{
	// variables
	int month;

	// code
	printf("\n\n");
	printf("Enter month: ");
	scanf("%d", &month);

	if (month == 1)
	{
		printf("month %d is January\n", month);
	}
	else if (month == 2)
	{
		printf("month %d is February\n", month);
	}
	else if (month == 3)
	{
		printf("month %d is March\n", month);
	}
	else if (month == 4)
	{
		printf("month %d is April\n", month);
	}
	else if (month == 5)
	{
		printf("month %d is May\n", month);
	}
	else if (month == 6)
	{
		printf("month %d is June\n", month);
	}
	else if (month == 7)
	{
		printf("month %d is July\n", month);
	}
	else if (month == 8)
	{
		printf("month %d is August\n", month);
	}
	else if (month == 9)
	{
		printf("month %d is September\n", month);
	}
	else if (month == 10)
	{
		printf("month %d is October\n", month);
	}
	else if (month == 11)
	{
		printf("month %d is November\n", month);
	}
	else if (month == 12)
	{
		printf("month %d is December\n", month);
	}
	else
	{
		printf("%d is invalid month number!\n", month);
	}

	printf("\n");
	return 0;
}