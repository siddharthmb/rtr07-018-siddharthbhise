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
	char ch;
	int ch_value;

	// code
	printf("\n\n");
	printf("Enter character: ");
	ch = getch();

	switch (ch)
	{
	case 'a':
	case 'A':
	case 'e':
	case 'E':
	case 'i':
	case 'I':
	case 'o':
	case 'O':
	case 'u':
	case 'U':
		printf("Character %c entered, is a vowel\n", ch);
		break;
	default:
		break;
	}

	ch_value = (int)ch;

	if ((ch_value >= A_ASCII && ch_value <= Z_ASCII) ||
		(ch_value >= a_ascii && ch_value <= z_ascii))
	{
		printf("Character %c entered is an alphabet from the English set of alphabets\n", ch);
	}
	else if (ch_value >= ZERO_ASCII && ch_value <= NINE_ASCII)
	{
		printf("Character %c entered is a digit\n", ch);
	}
	else
	{
		printf("Character %c entered is a special character!\n", ch);
	}

	printf("\n");
	return 0;
}