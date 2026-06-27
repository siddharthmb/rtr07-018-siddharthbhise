#include <stdio.h>

int main(void)
{
	// variables
	int i, j, c;

	// code
	printf("\n\n");
	for (i = 0; i < 64; ++i)
	{
		for (j = 0; j < 64; ++j)
		{
			c = ((i & 0x8) == 0) ^ ((j & 0x8) == 0);
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
		}
		printf("\n\n");
	}

	printf("\n");
	return 0;
}