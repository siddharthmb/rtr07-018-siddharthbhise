#include <stdio.h>

#define MAX_LEN 512

int main(void)
{
    // functions
    int smbstrlen(char[]);
    void smbstrcpy(char[], char[]);

    // variables
    char charArray[MAX_LEN];
    int length = 0;
    int i, wordcount = 0, spacecount = 0;

    // code
    printf("\n\n");
    printf("Enter string: ");
    gets_s(charArray, MAX_LEN);

    length = smbstrlen(charArray);
    for(i = 0; i < length; ++i)
    {
        switch(charArray[i])
        {
            case ' ':
            ++spacecount;
            break;
            default:
            break;
        }
    }

    wordcount = spacecount + 1;

    printf("The entered string '%s' contains %d words and %d spaces\n", charArray, wordcount, spacecount);

    return 0;
}

void smbstrcpy(char dest[], char source[])
{
    // variables
    int i, j;
    // code
    for(i = 0, j = 0; source[i] != '\0'; ++i)
    {
        dest[j++] = source[i];
    }

    dest[j] = '\0';
}

int smbstrlen(char s[])
{
    // variables
    int i = 0;
    // code
    while(i < MAX_LEN && s[i] != '\0') ++i;

    return i;
}
