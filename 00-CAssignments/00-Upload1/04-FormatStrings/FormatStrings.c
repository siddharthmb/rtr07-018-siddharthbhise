#include <stdio.h>

int main(void)
{
	// code

	printf("\n\n");

	printf("*************************************************************************************\n");
	int intVal = 3;
	printf("Integer Decimal Value of 'intVal' = %d\n", intVal);
	printf("Integer Octal Value of 'intVal' = %o\n", intVal);
	printf("Integer Hexadecimal Value of 'intVal' (in lower case): %x\n", intVal);
	printf("Integer Hexadecimal Value of 'intVal' (in upper case): %X\n", intVal);

	printf("\n\n");

	char c = 'A';
	printf("Character c = %c\n", c);
	char str[] = "Astromedicomp's RTR7 (Real Time Rendering, Batch no 7)";
	printf("String str = %s\n", str);

	long num = 1234567890L;
	printf("Long integer = %ld\n", num);

	unsigned int b = 7;
	printf("Unsigned int 'b' = %u\n", b);

	float floatPI = 3.14159265358979323846;
	printf("Double Precision Floating Point number (Pi) w/o Exponential = %g\n", floatPI);
	printf("Double Precision Floating Point number (Pi) w/ Exponential (lower case) = %e\n", floatPI);
	printf("Double Precision Floating Point number (Pi) w/ Exponential (upper case) = %E\n", floatPI);
	printf("Double Precision Floating Point number (Pi) (hex letters in lower case) = %a\n", floatPI);
	printf("Double Precision Floating Point number (Pi) (hex letters in upper case) = %A\n", floatPI);
	printf("*************************************************************************************\n");

	printf("\n\n");
	return 0;
}