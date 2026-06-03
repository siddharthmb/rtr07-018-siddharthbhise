#include <stdio.h>

int main(void)
{
	int a, b, result;

	printf("\n\n");
	printf("Enter value for \"a\" : ");
	scanf("%d", &a);

	printf("\n\n");
	printf("Enter value for \"b\": ");
	scanf("%d", &b);

	printf("\n\n");
	printf("##### 5 Arithmetic operators : +, -, *, / and % #####\n");
	result = a + b;
	printf("Adding a(%d) and b(%d) gives %d\n", a, b, result);
	result = a - b;
	printf("Subtracting a(%d) and b(%d) gives %d\n", a, b, result);
	result = a * b;
	printf("Multiplying a(%d) and b(%d) gives %d\n", a, b, result);
	result = a / b;
	printf("Dividing a(%d) and b(%d) gives %d\n", a, b, result);
	result = a % b;
	printf("Division a(%d) and b(%d) gives remainder %d\n", a, b, result);


	return 0;
}