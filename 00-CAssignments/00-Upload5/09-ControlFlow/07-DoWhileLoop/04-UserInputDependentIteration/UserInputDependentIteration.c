#include <stdio.h>

int main(void)
{
	// variables
	int iNum, num, i;

	// code
	printf("\n\n");
	printf("Enter the starting range number to print from: ");
	scanf("%d", &iNum);
	printf("Enter total numbers to print from %d: ", iNum);
	scanf("%d", &num);

	i = iNum;
	do
	{
		printf("\t%2d\n", i);
		++i;

	} while (i <= (iNum + num));

	printf("\n");
	return 0;
}