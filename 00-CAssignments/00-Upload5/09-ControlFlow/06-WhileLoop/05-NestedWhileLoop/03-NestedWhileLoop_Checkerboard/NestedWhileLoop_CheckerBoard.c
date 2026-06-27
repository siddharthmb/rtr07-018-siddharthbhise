#include <stdio.h>

int main(void)
{
	// variables
	int i, j, c;

	// code
	printf("\n\n");
	i = 0;
	while (i < 16)
	{
		j = 0;
		while (j < 16)
		{
			c = ((i & 0x4) == 0) ^ ((j & 0x4) == 0);
			if (c == 0)
				printf("  ");
			else
				printf("* ");

			++j;
		}

		printf("\n\n");
		++i;
	}

	printf("\n");
	return 0;
}