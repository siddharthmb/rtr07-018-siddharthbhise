#include <stdio.h>

int main(void)
{
    // variables
    int array[3][5];
    int intSize;
    int arraySize, numRows, numCols, numElements;
    int i, j;

    // code
    printf("\n\n");
    intSize = sizeof(int);
    arraySize = sizeof(array);
    numRows = arraySize / sizeof(array[0]);
    numCols = sizeof(array[0]) / intSize;
    numElements = numRows * numCols;

    printf("Array size: %d\n", arraySize);
    printf("Rows: %d\n", numRows);
    printf("Cols: %d\n", numCols);
    printf("Elements: %d\n", numElements);

    printf("\n\n");
    array[0][0] = 10;
    array[0][1] = 20;
    array[0][2] = 310;
    array[0][3] = 510;
    array[0][4] = 150;
    printf("\n\n");
    array[1][0] = 10;
    array[1][1] = 20;
    array[1][2] = 310;
    array[1][3] = 510;
    array[1][4] = 150;
    printf("\n\n");
    array[2][0] = 60;
    array[2][1] = 40;
    array[2][2] = 10;
    array[2][3] = 50;
    array[2][4] = 15;
    printf("\n\n");

    for(i = 0; i < numRows; ++i)
    {
        for(j = 0; j < numCols; ++j)
        {
            printf("array[i][j] = %d\n", array[i][j]);
        }
    }

    return 0;
}