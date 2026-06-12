#include <stdio.h>

int main(void)
{
	// functions
	void PrintBinaryFormOfNumber(const unsigned int, const char*);

	// variables
	unsigned int a;
	unsigned int b;
	unsigned int result;

	printf("\n\n");
	printf("Enter value of a: ");
	scanf("%u", &a);
	printf("Enter value of b: ");
	scanf("%u", &b);

	result = a | b;

	printf("\n\n");
	printf("%u | %u = %u\n", a, b, result);

	PrintBinaryFormOfNumber(a, "a = ");
	PrintBinaryFormOfNumber(b, "b = ");
	PrintBinaryFormOfNumber(result, "a | b = ");

	printf("\n\n");

	return 0;
}

void PrintBinaryFormOfNumber(const unsigned int number, const char* title)
{
	// variables
	int i = 7;
	unsigned int quotient;
	unsigned int remainder;
	unsigned int num = number;
	unsigned int arr[8] = { 0 };

	while (num != 0)
	{
		quotient = num / 2;
		remainder = num % 2;
		arr[i--] = remainder;
		num = quotient;
	}

	printf("%s", title);
	for (i = 0; i < 8; ++i)
	{
		printf("%u", arr[i]);
	}

	printf("\n");
}
