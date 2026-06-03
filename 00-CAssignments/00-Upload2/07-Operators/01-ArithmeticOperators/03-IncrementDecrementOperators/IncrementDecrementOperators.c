#include <stdio.h>

int main(void)
{
	int a = 5, b = 10;

	printf("\n\n");
	printf("'a' = %d\n", a);
	printf("'a++' = %d\n", a++);
	printf("'a--' = %d\n", a--);
	printf("'--a' = %d\n", --a);
	printf("'++a' = %d\n", ++a);
	printf("Final value of 'a' = %d\n", a);

	printf("\n");
	printf("'b' = %d\n", b);
	printf("'--b' = %d\n", --b);
	printf("'b++' = %d\n", b++);
	printf("'b--' = %d\n", b--);
	printf("'--b' = %d\n", --b);
	printf("Final value of 'b' = %d\n", b);


	return 0;
}