#include <stdio.h>

int main(void)
{
    // variables
    int array1[5], array2[5][3], array3[100][100][5];
    int numRows2D, numCols2D;
    int numRows3D, numCols3D, depth3D;

    // code
    printf("\n\n");
    printf("1D array : Size = %6zu\tElements = %6d\n", sizeof(array1), (int)(sizeof(array1) / sizeof(array1[0])));

    numRows2D = sizeof(array2) / sizeof(array2[0]);
    numCols2D = sizeof(array2[0]) / sizeof(array2[0][0]);
    printf("2D array : Size = %6zu\tElements = %6d\tRows = %5d\tCols = %5d\n",
        sizeof(array2),
        (int)(numRows2D * numCols2D),
        numRows2D,
        numCols2D
    );

    numRows3D = sizeof(array3) / sizeof(array3[0]);
    numCols3D = sizeof(array3[0]) / sizeof(array3[0][0]);
    depth3D   = sizeof(array3[0][0]) / sizeof(array3[0][0][0]);
    printf("3D array : Size = %6zu\tElements = %6d\tRows = %5d\tCols = %5d\tDepth = %d\n",
        sizeof(array3),
        (int)(numRows3D * numCols3D * depth3D),
        numRows3D,
        numCols3D,
        depth3D
    );

    printf("\n");
    return 0;
}