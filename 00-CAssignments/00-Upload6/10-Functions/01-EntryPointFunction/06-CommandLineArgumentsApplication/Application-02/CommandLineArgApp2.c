#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[], char* envp[])
{
	// variable
	int i;

	// code
	printf("\n\n");
	if (argc != 4)
	{
		printf("Invalid number of arguments!\n");
		printf("Usage: %s <firstName> <middleName> <lastName>\n", argv[0]);
		exit(1);
	}

	printf("Hello, ");
	for (i = 1; i < argc; i++)
	{
		printf("%s ", argv[i]);
	}

	printf("\b!\n");

	return 0;
}