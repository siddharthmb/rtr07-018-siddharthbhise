#include <stdio.h>
#include <string.h>

#define MAX_LEN 512

int main(void)
{
    // variables
    char charArray1[MAX_LEN], charArray2[MAX_LEN];

    // code
    printf("\n\n");
    printf("Enter first string: ");
    gets_s(charArray1, MAX_LEN);
    printf("Enter second string: ");
    gets_s(charArray2, MAX_LEN);

    printf("Concatenating '%s' and '%s', gave '%s'\n", charArray1, charArray2, strcat(charArray1, charArray2));

    return 0;
}