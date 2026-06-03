#include <stdio.h>

int main(void)
{
	int a, b, c, result;

	printf("\n\n");
	printf("Enter a number: ");
	scanf("%d", &a);

	printf("\n\n");
	printf("Enter b number: ");
	scanf("%d", &b);

	printf("\n\n");
	printf("Now, enter c number: ");
	scanf("%d", &c);

	printf("\n\n");

	printf("NOTE: Answer 0, means FALSE\n");
	printf("      Answer 1, means TRUE\n");
	printf("NOTE: a = %d, b = %d, c = %d\n\n", a, b, c);

	result = (a <= b) && (b != c);
	printf("result = (a <= b) && (b != c)\tgives %d\n", result);

	result = (b >= a) || (a == c);
	printf("result = (b >= a) || (a == c)\tgives %d\n", result);

	result = !a;
	printf("!a\t gives %d\n", result);

	result = !b;
	printf("!b\t gives %d\n", result);

	result = !c;
	printf("!c \t gives %d\n", result);

	result = (!(a <= b) && !(b != c));
	printf("result = (!(a <= b) && !(b != c))\tgives %d\n", result);

	result = !((b >= a) || (a == c));
	printf("result = !((b >= a) || (a == c))\tgives %d\n", result);

	printf("\n\n");

	return 0;
}