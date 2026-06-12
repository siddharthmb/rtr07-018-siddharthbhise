#include <stdio.h>

int main(void)
{
	// functions
	void PrintBinaryFormOfNumber(const unsigned int, const char *);

	// variables
	unsigned int a;
	unsigned int b;
	unsigned int result;

	// code
	printf("\n\n");
	printf("Enter an integer: ");
	scanf("%u", &a);

	printf("Enter another integer: ");
	scanf("%u", &b);

	printf("\n\n");
	result = a & b;
	printf("%u & %u = %u\n", a, b, result);

	PrintBinaryFormOfNumber(a, "a");
	PrintBinaryFormOfNumber(b, "b");
	PrintBinaryFormOfNumber(result, "a & b");

	return 0;
}

void PrintBinaryFormOfNumber(const unsigned int number, const char *title)
{
	// variables
	unsigned int quotient, remainder;
	unsigned int num;
	unsigned int arrBinary[8] = { 0 };
	int i;

	// code
	num = number;
	i = 7;	// last place in array
	while (num != 0)
	{
		quotient = num / 2;
		remainder = num % 2;
		arrBinary[i--] = remainder;
		num = quotient;
	}

	// print
	printf("%s => ", title);
	for(i = 0; i < 8; ++i)
	{
		printf("%u", arrBinary[i]);
	}

	printf("\n\n");
}
