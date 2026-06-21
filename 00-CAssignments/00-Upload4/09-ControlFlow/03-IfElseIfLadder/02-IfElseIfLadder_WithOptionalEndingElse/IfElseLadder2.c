#include <stdio.h>

int main(void)
{
	// variables
	int num;

	// code
	printf("\n\n");
	printf("Enter num: ");
	scanf("%d", &num);

	if (num < 0)
	{
		printf("num[%d] is less than 0\n", num);
	}
	else if (num > 0 && num <= 100)
	{
		printf("num[%d] is in interval (0, 100]\n", num);
	}
	else if (num > 100 && num <= 200)
	{
		printf("num[%d] is in interval (100, 200]\n", num);
	}
	else if (num > 200 && num <= 300)
	{
		printf("num[%d] is in interval (200, 300]\n", num);
	}
	else if (num > 300 && num <= 400)
	{
		printf("num[%d] is in interval (300, 400]\n", num);
	}
	else if (num > 400 && num <= 500)
	{
		printf("num[%d] is in interval (400, 500]\n", num);
	}
	else if (num > 500)
	{
		printf("num[%d] is greater than 500!\n", num);
	}
	else
	{
		printf("The last else-block! This only executes if the value entered is 0.\n");
	}

	printf("\n");
	return 0;
}