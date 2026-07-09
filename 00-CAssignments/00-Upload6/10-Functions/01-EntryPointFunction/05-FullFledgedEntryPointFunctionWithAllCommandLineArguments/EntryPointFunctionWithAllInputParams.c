#include <stdio.h>

int main(int argc, char* argv[], char* envp[])
{
	// variable declarations
	int i;

	// code
	printf("\n\n");
	printf("Hello, World!\n This function takes 3 input params and returns int.\n");
	printf("Total command lines args passed: %d\n", argc);
	for (i = 0; i < argc; ++i)
	{
		printf("Command line parameter number: %d, value = %s\n", i + 1, argv[i]);
	}

	printf("\n\n");
	printf("First 20 environmental parameters passed to our main are as follows:-\n");
	for (i = 0; i < 20; ++i)
	{
		printf("Environmental variable number %d = %s\n", i + 1, envp[i]);
	}

	printf("\n\n");

	return 0;
}