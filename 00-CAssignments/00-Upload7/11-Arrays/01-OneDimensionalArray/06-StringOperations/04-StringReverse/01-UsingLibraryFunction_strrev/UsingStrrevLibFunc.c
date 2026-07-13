#include <stdio.h>
#include <string.h>

#define MAX_LEN 512

int main(void)
{
    // variables
    char charArrayOriginal[MAX_LEN];

    // code
    printf("\n\n");
    printf("Enter the string: ");
    gets_s(charArrayOriginal, MAX_LEN);

    printf("You entered: %s\n", charArrayOriginal);
    printf("Reversed   : %s\n", strrev(charArrayOriginal));

    return 0;
}