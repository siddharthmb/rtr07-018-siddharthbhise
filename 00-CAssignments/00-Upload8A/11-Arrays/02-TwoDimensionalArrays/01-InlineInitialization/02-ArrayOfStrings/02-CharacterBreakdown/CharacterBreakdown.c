#include <stdio.h>

#define MAX_LEN 512

int main(void)
{
    // functions
    int smbstrlen(char[]);

    // variables
    char array[3][10] = {"Hello", "And", "Welcome"};
    int stringLengths[3];

    int arraySize;
    int arrayNumRows;
    int i, j;

    // code
    arraySize = sizeof(array);
    arrayNumRows = arraySize / sizeof(array[0]);

    // storing the lengths of all the strings
    for(i = 0; i < arrayNumRows; ++i)
    {
        printf("%s\n", array[i]);
        stringLengths[i] = smbstrlen(array[i]);
    }

    printf("\n\n");
    printf("Strings in the 2D array are: \n");

    for(i = 0; i < arrayNumRows; ++i)
    {
        for(j = 0; j < stringLengths[i]; ++j)
        {
            printf("Character %d = %c\n", j + 1, array[i][j]);
        }
        printf("\n\n");
    }

    return 0;
}

int smbstrlen(char s[])
{
    int i = 0;
    while(s[i++]);

    return i - 1;
}
