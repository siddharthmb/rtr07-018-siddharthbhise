#include <stdio.h>

int main(void)
{
	// variables
	int a, b, p, q;
	char ch_result_1, ch_result_2;
	int i_result_1, i_result_2;

	// code
	printf("\n\n");

	a = 7, b = 5;
	ch_result_1 = (a > b) ? 'a' : 'b';
	i_result_1  = (a > b) ? a : b;

	printf("Bigger among a and b, character-wise is %c, with int value %d\n", ch_result_1, i_result_1);

	p = 30, q = 30;
	ch_result_2 = (p != q) ? 'n' : 'y';
	i_result_2  = (p != q);
	printf("With 'y' as YES and 'n' as NO, are p and q equal? Ans is '%c', and their inequality comparison yielded %d\n", ch_result_2, i_result_2);

	printf("\n");

	return 0;
}