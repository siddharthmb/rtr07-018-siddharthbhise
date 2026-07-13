#include <stdio.h>

#define MAX_LEN 512

int main(void)
{
    // variables
    char charArrayOriginal[MAX_LEN], charArrayCopy[MAX_LEN];

    // code
    printf("\n\n");
    printf("Enter a string: ");
    gets_s(charArrayOriginal, MAX_LEN);

    strcpy(charArrayCopy, charArrayOriginal);

    printf("Original string entered is: %s\n", charArrayOriginal);
    printf("Copied string thus, is: %s\n", charArrayCopy);

    return 0;
}