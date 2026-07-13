#include <stdio.h>

#define MAX_LEN 512

int main(void)
{
    // functions
    void smbstrrev(char[], char[]);

    // variables
    char charArrayOrig[MAX_LEN], charArrayRev[MAX_LEN];

    // code
    printf("\n\n");
    printf("Enter the string to reverse: ");
    gets_s(charArrayOrig, MAX_LEN);

    smbstrrev(charArrayRev, charArrayOrig);

    printf("You entered: %s\n", charArrayOrig);
    printf("Reversed   : %s\n", charArrayRev);

    return 0;
}

void smbstrrev(char dest[], char source[])
{
    int j = 0;
    int i = strlen(source) - 1;
    while(i >= 0)
    {
        dest[j++] = source[i--];
    }

    dest[j] = '\0';
}
