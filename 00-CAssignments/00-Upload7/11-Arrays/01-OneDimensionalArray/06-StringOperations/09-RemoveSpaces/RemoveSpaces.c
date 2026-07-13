#include <stdio.h>

#define MAX_LEN 512

int main(void)
{
    // variables
    char string[MAX_LEN], string2[MAX_LEN];
    int i, j;

    // code
    printf("\n\n");
    printf("Enter a string: ");
    gets_s(string, MAX_LEN);

    for(j = 0, i = 0; string[i] != '\0'; ++i)
    {
        if(string[i] == ' ') continue;

        string2[j++] = string[i];
    }

    printf("You entered: %s\n", string);
    printf("Spaces removed: %s\n", string2);

    return 0;
}