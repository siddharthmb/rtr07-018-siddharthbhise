#include <stdio.h>

#define NUM_ROWS 5
#define NUM_COLS 3

int main(void)
{
    // variables
    int array2d[NUM_ROWS][NUM_COLS];
    int array1d[NUM_ROWS * NUM_COLS];
    int i, j;

    // code
    printf("\n\n");
    printf("Enter the elements of 2D array: \n");
    for(i = 0; i < NUM_ROWS; ++i)
    {
        for(j = 0; j < NUM_COLS; ++j)
        {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &array2d[i][j]);
        }
    }

    printf("\n\n");

    for(i = 0; i < NUM_ROWS; ++i)
    {
        for(j = 0; j < NUM_COLS; ++j)
        {
            printf("array2d[%d][%d] = %d\t", i, j, array2d[i][j]);
        }
        printf("\n");
    }

    // converting from 1d to 2d array
    for(i = 0; i < NUM_ROWS; ++i)
    {
        for(j = 0; j < NUM_COLS; ++j)
        {
            array1d[i * NUM_COLS + j] = array2d[i][j];
        }
    }

    printf("\n");

    printf("Converted 1d array is as follows: \n");
    for(i = 0; i < NUM_COLS * NUM_ROWS; ++i)
    {
        printf("%d ", array1d[i]);
    }

    printf("\n\n");

    return 0;
}