#include <stdio.h>

int main(void)
{
    // variables
    int array[3][3][2] = {
        {{10, 20}, {30, 40}, {50, 60}},
        {{1, 2}, {3, 4}, {5, 6}},
        {{15, 30}, {45, 60}, {75, 90}}
    };

    int intSize = sizeof(int);
    int arraySize = sizeof(array);
    int numRows = arraySize / sizeof(array[0]);
    int numCols = sizeof(array[0]) / sizeof(array[0][0]);
    int depth   = sizeof(array[0][0]) / intSize;
    int i, j, k;

    // code
    printf("\n\n");

    printf("Array size = %d\tRows = %d\tCols = %d\tDepth = %d\n", arraySize, numRows, numCols, depth);

    for(i = 0; i < numRows; ++i)
    {
        printf("--------------- ROW %d ---------------\n", i + 1);
        for(j = 0; j < numCols; ++j)
        {
            printf("Column %d: ", j + 1);
            for(k = 0; k < depth; ++k)
            {
                printf("array[%d][%d][%d] = %d ", i, j, k, array[i][j][k]);
            }
            printf("\n");
        }
        printf("\n\n");
    }

    printf("\n");
    return 0;
}