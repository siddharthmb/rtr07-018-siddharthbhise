#include <stdio.h>

#define A_ASCII 65
#define Z_ASCII 90

#define a_ascii 97
#define z_ascii 122

#define ZERO_ASCII 48
#define NINE_ASCII 57

int main(void)
{
	// variables
	int ch_value;
	char ch;

	// code
	printf("\n\n");
	printf("Enter character: ");
	ch = getch();

	if ((ch == 'a' || ch == 'A') ||
		(ch == 'e' || ch == 'E') ||
		(ch == 'i' || ch == 'I') ||
		(ch == 'o' || ch == 'O') ||
		(ch == 'u' || ch == 'U'))
	{
		printf("Entered character %c, is a vowel\n", ch);
	}
	ch_value = (int)ch;

	if ((ch_value >= A_ASCII && ch_value <= Z_ASCII) ||
		(ch_value >= a_ascii && ch_value <= z_ascii))
	{
		printf("Entered character %c, is an alphabet from English set of alphabets\n", ch);
	}
	else if (ch_value >= ZERO_ASCII && ch_value <= NINE_ASCII)
	{
		printf("Entered character %c, is a digit\n", ch);
	}
	else
	{
		printf("Entered character %c, is a special character!\n", ch);
	}

	printf("\n");
	return 0;
}