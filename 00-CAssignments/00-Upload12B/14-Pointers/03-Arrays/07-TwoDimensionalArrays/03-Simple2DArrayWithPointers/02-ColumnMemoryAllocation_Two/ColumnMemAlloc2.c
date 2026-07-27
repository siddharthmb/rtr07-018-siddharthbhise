#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS     5
#define NUM_COLS_ONE 3
#define NUM_COLS_TOW 8

int main(void)
{
    // variables
    int *iArray[NUM_ROWS];
    int i, j;

    // code
    printf("\n\n");
    printf("***** FIRST MALLOC TO 2D INT ARRAY *****\n");
    for(i = 0; i < NUM_ROWS; ++i)
    {
        iArray[i] = (int *)malloc(sizeof(int) * NUM_COLS_ONE);
        if(iArray[i] == NULL)
        {
            printf("Failed to allocate memory for row %d\n", i + 1);
            exit(1);
        }
    }

    // assigning values to 2d array
    for(i = 0; i < NUM_ROWS; ++i)
    {
        for(j = 0; j < NUM_COLS_ONE; ++j)
        {
            iArray[i][j] = (i + 1) * (j + 1);
            printf("iArray[%d][%d] = %d \t &iArray[%d][%d] = %p\n", i, j, iArray[i][j], i, j, &iArray[i][j]);
        }
    }

    printf("\n\n");
    printf("Freeing memory done in alloc 1\n");
    for(i = NUM_ROWS - 1; i >= 0; --i)
    {
        free(iArray[i]);
        iArray[i] = NULL;
        printf("Row %d freed...\n", i + 1);
    }

    printf("\n\n");
    printf("***** SECOND MALLOC TO 2D INT ARRAY *****\n");
    for(i = 0; i < NUM_ROWS; ++i)
    {
        iArray[i] = (int *)malloc(sizeof(int) * NUM_COLS_TOW);
        if(iArray[i] == NULL)
        {
            printf("Failed to allocate memory for row %d\n", i + 1);
            exit(1);
        }
    }

    for(i = 0; i < NUM_ROWS; ++i)
    {
        for(j = 0; j < NUM_COLS_TOW; ++j)
        {
            iArray[i][j] = (i + 1) * (j + 1);
            printf("iArray[%d][%d] = %d \t &iArray[%d][%d] = %p\n", i, j, iArray[i][j], i, j, &iArray[i][j]);
        }
    }

    printf("\n\n");
    printf("Freeing memory done in allocation2\n");
    for(i = NUM_ROWS - 1; i >= 0; --i)
    {
        free(iArray[i]);
        iArray[i] = NULL;
        printf("Row %d freed...\n", i + 1);
    }

    printf("\n");
    return 0;
}