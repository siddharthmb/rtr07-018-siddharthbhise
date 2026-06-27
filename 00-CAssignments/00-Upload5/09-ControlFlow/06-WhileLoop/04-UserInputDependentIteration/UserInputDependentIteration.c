#include <stdio.h>

int main(void)
{
	// variables
	int iNum, num, i;

	// code
	printf("\n\n");
	printf("Enter start of range to print: ");
	scanf("%d", &iNum);
	printf("Enter number of integers to print, starting with %d: ", iNum);
	scanf("%d", &num);

	i = iNum;
	while (i <= (iNum + num))
	{
		printf("\t%2d\n", i);
		++i;
	}

	printf("\n");
	return 0;
}