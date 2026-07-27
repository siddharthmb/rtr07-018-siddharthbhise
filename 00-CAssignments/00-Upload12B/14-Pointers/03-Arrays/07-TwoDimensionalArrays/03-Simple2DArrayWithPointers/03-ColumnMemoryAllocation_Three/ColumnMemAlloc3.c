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
    printf("***** 2D INT ARRAY MALLOC *****\n");
    for(i = 0; i < NUM_ROWS; ++i)
    {
        // variable sized cols
        iArray[i] = (int *)malloc(sizeof(int) * (NUM_ROWS - i));
        if(iArray[i] == NULL)
        {
            printf("Failed to allocate %zu bytes for row %d\n", (sizeof(int) * (NUM_ROWS - i)), i + 1);
            exit(1);
        }
    }

    // assigning values
    for(i = 0; i < NUM_ROWS; ++i)
    {
        for(j = 0; j < (NUM_ROWS - i); ++j)
        {
            iArray[i][j] = (i * 1) + (j * 1);
            printf("iArray[%d][%d] = %d \t &iArray[%d][%d] = %p\n", i, j, iArray[i][j], i, j, &iArray[i][j]);
        }
    }

    printf("\n\n");
    printf("Cleanup...\n");
    for(i = 0; i < NUM_ROWS; ++i)
    {
        free(iArray[i]);
        iArray[i] = NULL;
        printf("Row %d freed...\n", i + 1);
    }

    printf("\n");
    return 0;
}