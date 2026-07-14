#include <stdio.h>

#define MAX_LEN 512

int main(void)
{
    // variables
    char array[3][9];
    int arraySize, numRows, numElements, numCols;
    int charSize;
    int i;

    // code
    printf("\n\n");
    charSize = sizeof(char);
    arraySize = sizeof(array);
    numRows = arraySize / sizeof(array[0]);
    numCols = sizeof(array[0]) / charSize;
    numElements = numRows * numCols;

    printf("Array size : %d\n", arraySize);
    printf("Rows       : %d\n", numRows);
    printf("Cols       : %d\n", numCols);
    printf("Elements   : %d\n", numElements);

    printf("\n\n");

    array[0][0] = 'I';
    array[0][1] = '\0';
    array[1][0] = 'A';
    array[1][1] = 'M';
    array[1][2] = '\0';
    array[2][0] = 'S';
    array[2][1] = 'I';
    array[2][2] = 'D';
    array[2][3] = '\0';

    for(i = 0; i < numRows; ++i)
    {
        printf("%s ", array[i]);
    }

    printf("\n\n");

    return 0;
}