#include <stdio.h>

int main(int argc, char* argv[])
{
	// variable declarations
	int i;

	// code
	printf("\n\n");
	printf("Hello, World! This main takes 2 input params - argc, argv and returns and int.\n");
	for (i = 0; i < argc; ++i)
	{
		printf("Command line parameter number: %d, %s\n", i + 1, argv[i]);
	}

	printf("\n\n");

	return 0;
}