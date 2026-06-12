#include <stdio.h>

int main(void)
{
	// variables
	int i, j, a, result_int, i_explicit;
	float f, result_float, f_explicit;
	char ch1, ch2;

	printf("\n\n");

	i = 67;
	ch1 = i;
	printf("i = %d\n", i);
	printf("Character 1 assigned value of i = %c\n", ch1);

	ch2 = 'S';
	j = ch2;
	printf("character 2 initialized to %c\n", ch2);
	printf("j = character 2 in int = %d\n", j);

	printf("\n\n");
	// implicit conversion of int to float
	a = 4;
	f = 3.14f;
	result_float = a + f;
	printf("a(int) = %d, f(float) = %0.2f, when added, give sum of %0.2f\n", a, f, result_float);

	// explicit conversion using typecasting operator
	f_explicit = 3.1415f;
	i_explicit = (int)f_explicit;
	printf("floating point value to be typecasted to int => %f\n", f_explicit);
	printf("Resultant integer after typecasting to int => %d\n", i_explicit);

	printf("\n");
	return 0;
}