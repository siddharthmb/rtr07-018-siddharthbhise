#include <stdio.h>

int main(void)
{
	// code

	printf("\n\n");

	printf("\\n is an Escape Sequence used to go to the next line.\n\n");
	printf("This line\tcontains\ttabs\t. That's \\t Escape Sequence.\n\n");
	printf("\\\" is used to double-quote things, say, like my name => \"Siddharth\"\n\n");
	printf("Similarly, \\\' is used to \'single-quote\' something.\n\n");
	printf("BACKSPACE TURNED TO BACKSPACE\b using \\\b\n\n");
	printf("Now showing Carriage-Return (CR) using \\r Escape Sequence.\n\n");
	printf("Demonstrating Carriage \rReturn using \\r Escape Sequence.\n\n");
	printf("Demonstrating \x41 Using \\xhh Escape Sequence.\n 0x41 is the Hex Code for 'A', xhh is the placeholder for x\nfollowed by two digits.\n\n");
	printf("Demonstrating \102 Using \\ooo Escape Sequence. \n 102 is the Octal Code for 'B', ooo is the placeholder for 3 digits forming an octal number.\n\n");

	printf("\n\n");
	return 0;
}