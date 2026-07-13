#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    // variables
    char charArray[MAX_STRING_LENGTH];

    // code
    printf("\n\n");
    printf("Enter string: ");
    gets_s(charArray, MAX_STRING_LENGTH);
    printf("\n\n");
    printf("You entered: %s\n", charArray);

    return 0;
}