#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 512

int main(void)
{
    // functions
    void smbstrcat(char *dest, const char *strToAdd);

    // variables
    char *str1 = NULL;
    char *str2 = NULL;

    // code
    printf("\n\n");
    str1 = (char *)malloc(sizeof(char) * MAXLEN);
    if(str1 == NULL)
    {
        printf("Failed to allocate %zu bytes\n", sizeof(char) * MAXLEN);
        exit(1);
    }

    printf("Enter a string: ");
    gets_s(str1, MAXLEN);

    str2 = (char *)malloc(sizeof(char) * MAXLEN);
    if(str2 == NULL)
    {
        printf("Failed to allocate %zu bytes\n", sizeof(char) * MAXLEN);
        exit(1);
    }

    printf("Enter another string: ");
    gets_s(str2, MAXLEN);

    printf("\n\n");
    printf("***** BEFORE CONCAT *****\n");
    printf("\tstr1: %s\n", str1);
    printf("\tstr2: %s\n", str2);
    
    smbstrcat(str1, str2);

    printf("\n\n");
    printf("*****AFTER CONCAT *****\n");
    printf("\tstr1: %s\n", str1);
    printf("\tstr2: %s\n", str2);

    printf("\n\n");
    printf("Cleanup...\n");
    if(str1)
    {
        free(str1);
        str1 = NULL;
        printf("Freed memory allocated for str1...\n");
    }
    if(str2)
    {
        free(str2);
        str2 = NULL;
        printf("Freed memory allocated for str2...\n");
    }

    printf("\n");
    return 0;
}

void smbstrcat(char *dest, const char *toAdd)
{
    // functions
    int smbstrlen(const char *s);

    // variables
    int srclen = smbstrlen(toAdd);
    int destlen = smbstrlen(dest);
    char *d = &dest[destlen];
    char *s = (char *)toAdd;
    
    // code

    if(!d) return;
    if(srclen + destlen >= MAXLEN) return;

    while(s && *s)
    {
        *d = *s;
        ++d, ++s;
    }

    *d = '\0';
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
