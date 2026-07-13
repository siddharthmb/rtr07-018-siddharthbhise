#include <stdio.h>

#define MAX_LEN 512

int main(void)
{
    // variables
    char charArray[MAX_LEN];
    int stringLength = 0;

    // code
    printf("\n\n");
    printf("Enter the string: ");
    gets_s(charArray, MAX_LEN);

    printf("\n\n");
    printf("You entered: %s\n", charArray);

    // length
    stringLength = strlen(charArray);
    printf("This string has length of %d character[s]\n", stringLength);

    return 0;
}