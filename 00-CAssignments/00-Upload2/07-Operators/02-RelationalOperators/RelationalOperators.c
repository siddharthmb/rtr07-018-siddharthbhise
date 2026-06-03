#include <stdio.h>

int main(void)
{
	int a, b, result;

	printf("\n\n");
	printf("Enter a number: \n");
	scanf("%d", &a);
	printf("Enter another number: \n");
	scanf("%d", &b);

	printf("\n\n");
	printf("Evaluation to 0 means FALSE\n");
	printf("Evaluation to 1 means TRUE\n");
	printf("\n\n");

	printf("NOTE: a = %d\tb = %d\n\n", a, b);
	result = (a < b);
	printf("a < b gives %d\n", result);

	result = (a > b);
	printf("a > b gives %d\n", result);

	result = (a <= b);
	printf("a <= b gives %d\n", result);

	result = (a >= b);
	printf("a >= b gives %d\n", result);

	result = (a == b);
	printf("a == b gives %d\n", result);

	result = (a != b);
	printf("a != b gives %d\n", result);

	return 0;
}