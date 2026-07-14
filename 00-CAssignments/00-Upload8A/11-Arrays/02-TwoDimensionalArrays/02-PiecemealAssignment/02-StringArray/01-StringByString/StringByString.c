#include <stdio.h>

#define MAX_LEN 512

int main(void)
{
    // functions
    void smbstrcpy(char[], char[]);

    // variables
    char array[3][5];
    int charSize;
    int arraySize;
    int numRows, numCols, numElements, i;

    // code
    printf("\n\n");
    charSize = sizeof(char);
    arraySize = sizeof(array);
    numRows = arraySize / sizeof(array[0]);
    numCols = sizeof(array[0]) / charSize;
    numElements = numRows * numCols;

    printf("Array size : %d\n", charSize);
    printf("Rows       : %d\n", numRows);
    printf("Cols       : %d\n", numCols);
    printf("Elements   : %d\n", numElements);

    // piecemeal assignment
    smbstrcpy(array[0], "I");
    smbstrcpy(array[1], "Am");
    smbstrcpy(array[2], "Sid");

    printf("\n\n");
    printf("The strings in the array are: \n");
    for(i = 0; i < numRows; ++i)
    {
        printf("%s ", array[i]);
    }

    printf("\n\n");

    return 0;
}

void smbstrcpy(char dest[], char source[])
{
    int i = 0, j = 0;
    while(source[i])
    {
        dest[j++] = source[i++];
    }

    dest[j] = '\0';
}
