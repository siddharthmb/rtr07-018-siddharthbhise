#include <stdio.h>

int main(void)
{
    // variables
    int arr[5][3] = {{10, 20, 30}, {40, 50, 70}, {110, 98, 65}, {54, 987, 876}, {56, 54, 56}};
    int intSize = sizeof(int);
    int arraySize;
    int arrayTotalElements, arrayTotalRows, arrayTotalColumns;

    // code
    printf("\n\n");
    arraySize = sizeof(arr);
    printf("Size of the 2D array of ints is %d\n", arraySize);

    arrayTotalRows = arraySize / sizeof(arr[0]);
    arrayTotalColumns = sizeof(arr[0]) / intSize;
    arrayTotalElements = arrayTotalRows * arrayTotalColumns;

    printf("Array size = %u\tTotal rows = %d\tTotal columns = %d\tTotal elements = %d\n", arraySize, arrayTotalRows, arrayTotalColumns, arrayTotalElements);
    printf("\n\n");

    printf("arr[0][0] = %d\t", arr[0][0]);
    printf("arr[0][1] = %d\t", arr[0][1]);
    printf("arr[0][2] = %d", arr[0][2]);
    printf("\n\n");
    printf("arr[1][0] = %d\t", arr[1][0]);
    printf("arr[1][1] = %d\t", arr[1][1]);
    printf("arr[1][2] = %d"  , arr[1][2]);
    printf("\n\n");
    printf("arr[2][0] = %d\t", arr[2][0]);
    printf("arr[2][1] = %d\t", arr[2][1]);
    printf("arr[2][2] = %d"  , arr[2][2]);
    printf("\n\n");
    printf("arr[3][0] = %d\t", arr[3][0]);
    printf("arr[3][1] = %d\t", arr[3][1]);
    printf("arr[3][2] = %d",   arr[3][2]);
    printf("\n\n");
    printf("arr[4][0] = %d\t", arr[4][0]);
    printf("arr[4][1] = %d\t", arr[4][1]);
    printf("arr[4][2] = %d"  , arr[4][2]);
    printf("\n\n");

    return 0;
}