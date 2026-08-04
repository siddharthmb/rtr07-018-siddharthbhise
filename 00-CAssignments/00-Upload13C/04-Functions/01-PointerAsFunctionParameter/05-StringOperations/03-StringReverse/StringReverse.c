#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 512

int main(void)
{
    // functions
    void smbstrrev(char *dest, const char *src);
    int smbstrlen(const char *);

    // variables 
    char *str = NULL;
    char *strRev = NULL;
    int origStringLength;

    // code
    printf("\n\n");
    str = (char *)malloc(sizeof(char) * MAX_LEN);
    if(str == NULL)
    {
        printf("Failed to allocate %zu bytes\n", sizeof(char) * MAX_LEN);
        exit(1);
    }

    printf("Enter the string: ");
    gets_s(str, MAX_LEN);

    origStringLength = smbstrlen(str);
    strRev = (char *)malloc(sizeof(char) * origStringLength);
    if(strRev == NULL)
    {
        printf("Failed to allocate %zu bytes\n", sizeof(char) * origStringLength);
        exit(1);
    }

    smbstrrev(strRev, str);
    printf("Original string: %s\n", str);
    printf("Reversed string: %s\n", strRev);

    printf("\n\n");
    printf("Cleanup...\n");
    if(str)
    {
        free(str);
        str = NULL;
        printf("Freed space for original string...\n");
    }
    if(strRev)
    {
        free(strRev);
        strRev = NULL;
        printf("Freed space for reversed string...\n");
    }

    printf("\n");
    return 0;
}

int smbstrlen(const char *s)
{
    // variables
    char *p = (char *)s;
    int length = 0;
 
    // code
    while(p && *p++) ++length;

    return length;
}

void smbstrrev(char *dest, const char *src)
{
    // variables
    char *d = dest;
    int srclen = smbstrlen(src);
    char *s = (char *)&src[srclen - 1];

    while(srclen--)
    {
        *d = *s;
        ++d;
        --s;
    }

    *d = '\0';
}
