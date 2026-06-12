#include <stdio.h>

int main(void)
{
	// functions
	void PrintBinaryFromDecimal(const unsigned int, const char *);

	// variables
	unsigned int a;
	unsigned int result;

	// code
	printf("\n\n");

	printf("Enter value of a: ");
	scanf("%u", &a);

	result = ~a;
	printf("~%u = %u\n", a, result);

	PrintBinaryFromDecimal(a, "a = ");
	PrintBinaryFromDecimal(result, "~a = ");

	printf("\n");
	return 0;
}

void PrintBinaryFromDecimal(const unsigned int number, const char* title)
{
	// variables
	unsigned int quotient, remainder;
	unsigned int arr[8] = { 0 };
	int i = 7;
	unsigned int num = number;

	while (num != 0)
	{
		quotient = num / 2;
		remainder = num % 2;
		arr[i--] = remainder;
		num = quotient;
	}

	printf(title);
	for (i = 0; i < 8; ++i)
	{
		printf("%u", arr[i]);
	}

	printf("\n");
}
