#include <stdio.h>

int main(void)
{
	// variables
	int num;

	// code
	printf("\n\n");
	printf("Enter num: ");
	scanf("%d", &num);

	if (num <= 0)
	{
		printf("num[%d] is less than OR equal to 0\n", num);
	}
	else if (num > 0 && num <= 100)
	{
		printf("num[%d] is within interval (0, 100]\n", num);
	}
	else if (num > 100 && num <= 200)
	{
		printf("num[%d] is within interval (100, 200]\n", num);
	}
	else if (num > 200 && num <= 300)
	{
		printf("num[%d] is within interval (200, 300]\n", num);
	}
	else if (num > 300 && num <= 400)
	{
		printf("num[%d] is within interval (300, 400]\n", num);
	}
	else if (num > 400 && num <= 500)
	{
		printf("num[%d] is within interval (400, 500]\n", num);
	}
	else
	{
		printf("num[%d] is greater than 500!\n", num);
	}

	printf("\n");
	return 0;
}