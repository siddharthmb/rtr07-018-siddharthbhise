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
		printf("You are eligible for voting\n");
	}

	printf("You are not eligible for voting\n\n");
	printf("THIS ABOVE CONFUSING OUTPUT IS BECAUSE THE PROGRAM IS NOT WRITTEN WITH THE else FOR THE if THAT EXISTS!\nTHIS PROGRAM IS TO ILLUSTRATE BAD CODING!\n");

	printf("\n");
	return 0;
}