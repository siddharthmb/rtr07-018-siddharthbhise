#include <stdio.h>

int main(void)
{
	// functions
	void PrintBinaryOfNumber(const unsigned int, const char *);

	// variables
	unsigned int a, result, shift_by;

	printf("\n\n");
	printf("Enter value of a: ");
	scanf("%u", &a);
	printf("Enter value for right shift by: ");
	scanf("%u", &shift_by);

	result = a >> shift_by;
	printf("%u >> %u = %u\n", a, shift_by, result);

	PrintBinaryOfNumber(a, "a = ");
	PrintBinaryOfNumber(result, "result = ");

	printf("\n");
	return 0;
}

void PrintBinaryOfNumber(const unsigned int number, const char* title)
{
	// variables
	unsigned int quotient, remainder, num = number;
	unsigned int arr[8] = { 0 };
	int i = 7;

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
