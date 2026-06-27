#include <stdio.h>

int main(void)
{
	// variables
	int i, j, c;

	// code
	printf("\n\n");

	i = 0;
	do
	{
		j = 0;
		do
		{
			c = ((i & 0x2) == 0) ^ ((j & 0x2) == 0);
			switch (c)
			{
			case 0:
				printf("  ");
				break;
			case 1:
				printf("* ");
				break;
			default:
				break;
			}

			++j;

		} while (j < 4);

		printf("\n\n");
		++i;

	} while (i < 4);

	printf("\n");
	return 0;
}