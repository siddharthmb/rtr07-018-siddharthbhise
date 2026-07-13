#include <stdio.h>
#include <string.h>

#define MAX_LEN 512

int main(void)
{
    // functions
    void smbstrcat(char[], char[]);

    // variables
    char charArray1[MAX_LEN], charArray2[MAX_LEN];

    // code
    printf("\n\n");

    printf("Enter the first string: ");
    gets_s(charArray1, MAX_LEN);
    printf("Enter the second string: ");
    gets_s(charArray2, MAX_LEN);

    printf("You entered 2 strings as follows\n1: %s\n2: %s\n\n", charArray1, charArray2);

    smbstrcat(charArray1, charArray2);

    printf("After smbconcat function is called on above strings, below is the result\n");
    printf("1: %s\n2: %s\n\n", charArray1, charArray2);

    return 0;
}

void smbstrcat(char dest[], char source[])
{
    int i = 0;
    int j = strlen(dest);

    while(j < MAX_LEN && source[i] != '\0')
    {
        dest[j++] = source[i++];
    }

    dest[j] = '\0';
}