#include <stdio.h>

int main(void)
{
	// variables
	int month;

	// code
	printf("\n\n");
	printf("Enter month: ");
	scanf("%d", &month);

	switch (month)
	{
	case 1:
		printf("month %d, is JANUARY\n", month);
		break;
	case 2:
		printf("month %d, is FEBRUARY\n", month);
		break;
	case 3:
		printf("month %d, is MARCH\n", month);
		break;
	case 4:
		printf("month %d, is APRIL\n", month);
		break;
	case 5:
		printf("month %d, is MAY\n", month);
		break;
	case 6:
		printf("month %d, is JUNE\n", month);
		break;
	case 7:
		printf("month %d, is JULY\n", month);
		break;
	case 8:
		printf("month %d, is AUGUST\n", month);
		break;
	case 9:
		printf("month %d, is SEPTEMBER\n", month);
		break;
	case 10:
		printf("month %d, is OCTOBER\n", month);
		break;
	case 11:
		printf("month %d, is NOVEMBER\n", month);
		break;
	case 12:
		printf("month %d, is DECEMBER\n", month);
		break;
	default:
		printf("[Error] Invalid month entered: %d\n", month);
		break;
	}

	printf("\n");
	return 0;
}