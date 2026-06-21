#include <stdio.h>

int main(void)
{
	// variables
	int age;

	// code
	printf("\n\n");
	printf("Enter age: ");
	scanf("%d", &age);

	if (age >= 18)
	{
		printf("You are eligible for voting!\n");
	}
	else
	{
		printf("NOT eligible for voting, you are!\n");
	}

	printf("\n");
	return 0;
}