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
		printf("You are eligible for voting, vote wisely!\n");
	}
	else
	{
		printf("You are not yet eligible for voting, your age, %d, is less than 18.\n", age);
	}

	printf("\n");
	return 0;
}