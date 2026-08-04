#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 512

int main(void)
{
    // functions
    char *replaceVowelsWithAtTheRate(char *);

    // variables
    char str[MAXLEN];
    char *replacedString = NULL;

    // code
    printf("\n\n");
    printf("Enter the string: ");
    gets_s(str, MAXLEN);

    replacedString = replaceVowelsWithAtTheRate(str);
    if(replacedString == NULL)
    {
        printf("replaceVowelsWithAtTheRate() returned NULL\n");
        exit(1);
    }

    printf("Original string : %s\n", str);
    printf("Replaced string : %s\n", replacedString);

    printf("\n\n");
    printf("Cleanup...\n");

    if(replacedString)
    {
        free(replacedString);
        replacedString = NULL;
        printf("Freed bytes allocated for the replaced string...\n");
    }

    printf("\n");
    return 0;
}

char *replaceVowelsWithAtTheRate(char *str)
{
    // functions
    int smbstrlen(const char *);

    // variables
    char *s = str;
    int len = smbstrlen(str);
    char *d = NULL;
    char *retstr = (char *)malloc(sizeof(char) * len);
    if(retstr == NULL)
    {
        printf("Fatal error, failure in malloc while allocating %zu bytes\n", sizeof(char) * len);
        exit(1);
    }
    d = retstr;

    while(s && *s)
    {
        switch(*s)
        {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                *d = '@';
            break;
            default:
                *d = *s;
            break;
        }

        ++d, ++s;
    }

    return retstr;
}

int smbstrlen(const char *src)
{
    // variables
    char *s = (char *)src;
    int len = 0;

    // code
    while(s && *s++) ++len;

    return len;
}
