#include <stdio.h>

#define MAX_LEN 512

int main(void)
{
    // functions
    void smbstrcpy(char[], char[]);

    // variables
    char charArrayOrig[MAX_LEN], charArrayCopy[MAX_LEN];

    // code
    printf("\n\n");
    printf("Enter the string: ");
    gets_s(charArrayOrig, MAX_LEN);

    smbstrcpy(charArrayCopy, charArrayOrig);

    printf("Original string: %s\n", charArrayOrig);
    printf("Copied string: %s\n", charArrayCopy);

    return 0;
}

void smbstrcpy(char dest[], char source[])
{
    int i;
    for(i = 0; source[i] != '\0'; ++i)
    {
        dest[i] = source[i];
    }

    dest[i] = '\0';
}