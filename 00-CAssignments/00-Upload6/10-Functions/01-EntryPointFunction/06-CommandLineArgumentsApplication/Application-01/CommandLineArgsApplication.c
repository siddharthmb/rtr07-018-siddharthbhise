#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[], char* envp[])
{
	// variable declarations
	int i, num, sum = 0;

	// code
	printf("\n\n");

	if (argc == 1)
	{
		printf("Usage: %s <arg1, arg2, ...>\n\n", argv[0]);
		exit(0);
	}

	for (i = 1; i < argc; ++i)
	{
		num = atoi(argv[i]);
		sum = sum + num;
	}

	printf("Sum of all command line arguments is: %d\n", sum);

	return 0;
}