#include <stdio.h>

#define MAX_LEN 512

int main(void)
{
    // functions
    int smbstrlen(char[]);

    // variables
    char charArray[MAX_LEN];
    int len = 0;

    // code
    printf("\n\n");
    printf("Enter a string: ");
    gets_s(charArray, MAX_LEN);
    printf("You entered: %s\n", charArray);
    // length
    len = smbstrlen(charArray);
    printf("Length of the string is: %d\n", len);

    return 0;
}

int smbstrlen(char s[])
{
    // variables
    int i;
    int length = 0;

    // code
    for(i = 0; i < MAX_LEN; ++i)
    {
        if(s[i] == '\0') break;
        ++length;
    }

    return length;
}
