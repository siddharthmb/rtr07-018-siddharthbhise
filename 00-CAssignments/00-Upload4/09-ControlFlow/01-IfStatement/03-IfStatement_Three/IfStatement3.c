#include <stdio.h>

int main(void)
{
	// variables
	int num;

	// code
	printf("\n\n");
	printf("Enter value of num: ");
	scanf("%d", &num);

	if (num < 0)
	{
		printf("num[%d] is less than 0\n", num);
	}

	if (num > 0 && num <= 100)
	{
		printf("num[%d] is within the interval (0, 100]\n", num);
	}

	if (num > 100 && num <= 200)
	{
		printf("num[%d] is within the interval (100, 200]\n", num);
	}

	if (num > 200 && num <= 300)
	{
		printf("num[%d] is within the interval (200, 300]\n", num);
	}

	if (num > 300 && num <= 400)
	{
		printf("num[%d] is within the interval (300, 400]\n", num);
	}

	if (num > 500)
	{
		printf("num[%d] is greater than 500\n", num);
	}

	printf("\n");
	return 0;
}