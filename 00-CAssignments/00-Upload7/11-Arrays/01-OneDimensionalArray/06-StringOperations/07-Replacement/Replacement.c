#include <stdio.h>

#define MAX_LEN 512

int main(void)
{
    // functions
    void smbstrcpy(char[], char[]);
    int smbstrlen(char[]);

    // variables
    char string1[MAX_LEN], stringcopy[MAX_LEN];
    int len, i;

    // code
    printf("\n\n");
    printf("Enter a string: ");
    gets_s(string1, MAX_LEN);

    smbstrcpy(stringcopy, string1);
    len = smbstrlen(stringcopy);
    for(i = 0; i < len; ++i)
    {
        switch(stringcopy[i])
        {
            case 'A':
            case 'a':
            case 'E':
            case 'e':
            case 'I':
            case 'i':
            case 'O':
            case 'o':
            case 'U':
            case 'u':
            stringcopy[i] = '*';
            break;
            default:
            break;
        }
    }

    printf("After replacing vowels, the string looks like: %s\n", stringcopy);

    return 0;
}

void smbstrcpy(char dest[], char source[])
{
    // variables
    int sourceLength = smbstrlen(source);
    int i = 0, j = 0;
    // code
    for(; i < sourceLength; ++i)
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
    while(i < MAX_LEN && s[i++] != '\0');

    return i;
}
