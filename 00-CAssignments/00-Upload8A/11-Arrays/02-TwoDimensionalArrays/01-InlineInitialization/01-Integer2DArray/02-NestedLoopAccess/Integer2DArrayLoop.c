#include <stdio.h>

int main(void)
{
    // variables
    int arr[5][3] = {{567, 567, 5678}, {76, 9876, 567}, {76, 9876, 45}, {90, 78, 6}, {34, 3, 2}};
    int i, j, numRows, numCols, totalElements;

    numRows = sizeof(arr) / sizeof(arr[0]);
    numCols = sizeof(arr[0]) / sizeof(int);

    // code
    printf("Array size= %zu\tRows = %d\tCols = %d\tElements = %d\n", 
        sizeof(arr),
        numRows,
        numCols,
        numRows * numCols
    );

    for(i = 0; i < numRows; i++)
    {
        for(j = 0; j < numCols; ++j)
        {
            printf("arr[%d][%d] = %d\t", i, j, arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}