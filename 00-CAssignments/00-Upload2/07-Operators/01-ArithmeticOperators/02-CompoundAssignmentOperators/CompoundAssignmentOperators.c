#include <stdio.h>

int main(void)
{
	int a, b, x;

	printf("\n\n");
	printf("Enter value for 'a': ");
	scanf("%d", &a);
	printf("Enter value for 'b': ");
	scanf("%d", &b);

	printf("\n\n");
	x = a;
	a += b;
	printf("a += b changed a from %d to %d\n", x, a);

	x = a;
	a -= b;
	printf("Subtracting b(%d) from new value of x(%d) changed it to %d\n", b, x, a);

	x = a;
	a *= b;
	printf("Yet new value of a(%d), when multiplied by b(%d), gave %d\n", x, b, a);

	x = a;
	a /= b;
	printf("Still newer value of a(%d), when divided by b(%d), gave %d\n", x, b, a);

	x = a;
	a %= b;
	printf("Final value of a(%d) was obtained by dividing a(%d) by b(%d)\n", a, x, b);

	return 0;
}