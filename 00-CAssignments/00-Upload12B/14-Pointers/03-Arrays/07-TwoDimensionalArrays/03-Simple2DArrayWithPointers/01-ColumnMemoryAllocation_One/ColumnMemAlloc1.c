#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLS 3

int main(void)
{
    // variables
    int *iArray[NUM_ROWS];
    int i, j;

    // code
    printf("\n\n");
    for(i = 0; i < NUM_ROWS; ++i)
    {
        iArray[i] = (int *)malloc(sizeof(int) * NUM_COLS);
        if(iArray[i] == NULL)
        {
            printf("Memory allocation failed for row number %d\n", i);
            exit(1);
        }
    }

    for(i = 0; i < NUM_ROWS; ++i)
    {
        for(j = 0; j < NUM_COLS; ++j)
        {
            iArray[i][j] = (i + 1) * (j + 1);
            printf("iArray[%d][%d] = %d \t &iArray[%d][%d] = %p\n", i, j, iArray[i][j], i, j, &iArray[i][j]);
        }
    }

    printf("\n\n");
    printf("Cleanup...\n");
    for(i = NUM_ROWS - 1; i >= 0; --i)
    {
        free(iArray[i]);
        iArray[i] = NULL;
        printf("Row %d freed...\n", i + 1);
    }

    printf("\n");
    return 0;
}