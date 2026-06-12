#include <stdio.h>

int main(void)
{
	// functions
	void PrintNumberInBinary(const unsigned int, const char *);

	// variables
	unsigned int a, b, result;

	// code
	printf("\n\n");
	printf("Enter value of a: ");
	scanf("%u", &a);

	printf("Enter value of b: ");
	scanf("%u", &b);

	printf("\n\n");
	result = a ^ b;

	printf("%u ^ %u = %u\n", a, b, result);

	PrintNumberInBinary(a, "a = ");
	PrintNumberInBinary(b, "b = ");
	PrintNumberInBinary(result, "result = ");

	printf("\n");

	return 0;
}

void PrintNumberInBinary(const unsigned int number, const char* title)
{
	// variables
	int i = 7;
	unsigned int arr[8] = { 0 };
	unsigned int remainder, quotient;
	unsigned int num = number;

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
