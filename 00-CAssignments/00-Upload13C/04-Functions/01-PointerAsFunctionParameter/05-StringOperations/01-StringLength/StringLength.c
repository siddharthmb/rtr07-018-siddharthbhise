#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 512

int main(void)
{
    // functions
    int smbstrlen(const char *);
    void smbgets_s(char *, int);

    // variables
    char *str = NULL;
    int length = 0;

    // code
    printf("\n\n");
    str = (char *)malloc(MAX_LEN * sizeof(char));
    if(str == NULL)
    {
        printf("Failed to allocated %zu bytes\n", sizeof(char) * MAX_LEN);
        exit(1);
    }

    printf("Enter a string: ");
    gets_s(str, MAX_LEN);

    length = smbstrlen(str);
    printf("You entered a string %s, which is of length %d\n", str, length);

    printf("\n\n");
    printf("Cleanup...\n");

    if(str)
    {
        free(str);
        str = NULL;
        printf("freed %zu bytes...\n", sizeof(char) * MAX_LEN);
    }

    printf("\n");
    return 0;
}

int smbstrlen(const char *s)
{
    // variables
    char *p = (char *)s;
    int len = 0;

    // code
    while(p && *p++) ++len;

    return len;
}
