#include <stdio.h>

int main(void)
{
	// code
	int	   intValue	   = 14;
	float  floatValue  = 13.0f;
	double doubleValue = 3.142857;
	char   charValue   = 'A';

	printf("\n\n");

	printf("int    value = %d\n", intValue);
	printf("float  value = %.2f\n", floatValue);
	printf("double value = %.2lf\n", doubleValue);
	printf("char   value = %c\n", charValue);

	printf("\n\n");

	intValue    = 100;
	floatValue  = 6.28f;
	doubleValue = 12.56;
	charValue   = 'S';

	printf("int    value = %d\n", intValue);
	printf("float  value = %f\n", floatValue);
	printf("double value = %lf\n", doubleValue);
	printf("char   value = %c\n", charValue);

	printf("\n\n");

	return 0;
}
