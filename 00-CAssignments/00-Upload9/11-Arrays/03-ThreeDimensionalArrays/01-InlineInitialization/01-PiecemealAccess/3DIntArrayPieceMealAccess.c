#include <stdio.h>

int main(void)
{
    // variables
    // inline init
    int array[5][3][2] = {
        {{12, 24}, {36, 48}, {60, 72}},
        {{11, 22}, {33, 44}, {55, 66}},
        {{5, 10}, {15, 20}, {25, 30}},
        {{3, 6}, {9, 12}, {15, 18}},
        {{1, 2}, {9, 16}, {25, 36}}
    };

    int intSize = sizeof(int);
    int arraySize = sizeof(array);
    int numRows = arraySize / sizeof(array[0]);
    int numCols = sizeof(array[0]) / sizeof(array[0][0]);
    int depth   = sizeof(array[0][0]) / sizeof(array[0][0][0]);

    // code
    printf("\n\n");
    printf("Array size = %d\tRows = %d\tCols = %d\tDepth = %d\tTotal Elements = %d\n", arraySize, numRows, numCols, depth, numRows * numCols * depth);
    printf("\n\n");


    printf("--------------- Row 1 ---------------\n");
    printf("Column 1: array[0][0][0] = %d\tarray[0][0][1] = %d\n", array[0][0][0], array[0][0][1]);
    printf("Column 2: array[0][1][0] = %d\tarray[0][1][1] = %d\n", array[0][1][0], array[0][1][1]);
    printf("Column 3: array[0][2][0] = %d\tarray[0][2][1] = %d\n", array[0][2][0], array[0][2][1]);

    printf("--------------- Row 2 ---------------\n");
    printf("Column 1: array[1][0][0] = %d\tarray[1][0][1] = %d\n", array[1][0][0], array[1][0][1]);
    printf("Column 2: array[1][1][0] = %d\tarray[1][1][1] = %d\n", array[1][1][0], array[1][1][1]);
    printf("Column 3: array[1][2][0] = %d\tarray[1][2][1] = %d\n", array[1][2][0], array[1][2][1]);

    printf("--------------- Row 3 ---------------\n");
    printf("Column 1: array[2][0][0] = %d\tarray[2][0][1] = %d\n", array[2][0][0], array[2][0][1]);
    printf("Column 2: array[2][1][0] = %d\tarray[2][1][1] = %d\n", array[2][1][0], array[2][1][1]);
    printf("Column 3: array[2][2][0] = %d\tarray[2][2][1] = %d\n", array[2][2][0], array[2][2][1]);

    printf("--------------- Row 4 ---------------\n");
    printf("Column 1: array[3][0][0] = %d\tarray[3][0][1] = %d\n", array[3][0][0], array[3][0][1]);
    printf("Column 2: array[3][1][0] = %d\tarray[3][1][1] = %d\n", array[3][1][0], array[3][1][1]);
    printf("Column 3: array[3][2][0] = %d\tarray[3][2][1] = %d\n", array[3][2][0], array[3][2][1]);

    printf("--------------- Row 5 ---------------\n");
    printf("Column 1: array[4][0][0] = %d\tarray[4][0][1] = %d\n", array[4][0][0], array[4][0][1]);
    printf("Column 2: array[4][1][0] = %d\tarray[4][1][1] = %d\n", array[4][1][0], array[4][1][1]);
    printf("Column 3: array[4][2][0] = %d\tarray[4][2][1] = %d\n", array[4][2][0], array[4][2][1]);

    printf("\n");
    return 0;
}