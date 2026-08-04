#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 512

int main(void)
{
    // functions
    void smbstrcpy(char *dest, const char *src);
    int smbstrlen(const char *s);

    // variables
    char *str = NULL;
    char *strCopy = NULL;
    int origStrLength;

    // code
    printf("\n\n");
    str = (char *)malloc(sizeof(char) * MAX_LEN);
    if(str == NULL)
    {
        printf("Failed to allocated %d bytes\n", MAX_LEN);
        exit(1);
    }

    printf("Enter original string: ");
    gets_s(str, MAX_LEN);

    origStrLength = smbstrlen(str);
    strCopy = (char *)malloc(sizeof(char) * origStrLength);
    if(strCopy == NULL)
    {
        printf("Failed to allocated %d bytes\n", origStrLength);
        exit(1);
    }

    smbstrcpy(strCopy, str);

    printf("\n\n");
    printf("Original string: %s\n", str);
    printf("Copied string: %s\n", strCopy);

    printf("\n\n");
    if(str)
    {
        free(str);
        str = NULL;
        printf("Freed original string's memory...\n");
    }
    if(strCopy)
    {
        free(strCopy);
        strCopy = NULL;
        printf("Freed copied string's memory...\n");
    }

    printf("\n");
    return 0;
}

int smbstrlen(const char *s)
{
    char *p = (char *)s;
    int len = 0;
    while(p && *p++) ++len;

    return len;
}

void smbstrcpy(char *dest, const char *src)
{
    char *d = dest;
    char *s = (char *)src;

    while(s && *s)
    {
        *d = *s;
        ++d;
        ++s;
    }

    *d = '\0';
}
