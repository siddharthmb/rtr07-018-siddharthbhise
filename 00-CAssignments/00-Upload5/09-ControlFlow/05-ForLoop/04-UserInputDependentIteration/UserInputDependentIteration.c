#include <stdio.h>

int main(void)
{
	// variables
	int iNum, num, i;

	// code
	printf("\n\n");
	printf("Enter int value from that works as start of iteration: ");
	scanf("%d", &iNum);
	printf("How many digits to print, starting with %d? : ", iNum);
	scanf("%d", &num);

	printf("\n");
	for (i = iNum; i <= (iNum + num); ++i)
	{
		printf("\t%2d\n", i);
	}

	printf("\n");
	return 0;
}