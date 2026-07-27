#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLS 3

int main(void)
{
    // variables
    int i, j;
    int **p_iArray = NULL;

    // code
    printf("\n\n");

    p_iArray = (int **)malloc(NUM_ROWS * sizeof(int *));
    if(p_iArray == NULL)
    {
        printf("Memory allocation failed for int **, total %zu bytes\n", sizeof(int *) * NUM_ROWS);
        exit(1);
    }

    for(i = 0; i < NUM_ROWS; ++i)
    {
        p_iArray[i] = (int *)malloc(sizeof(int) * NUM_COLS);
        if(p_iArray[i] == NULL)
        {
            printf("Failed to allocate memory for int *, totay %zu bytes\n", sizeof(int) * NUM_COLS);
            exit(1);
        }
    }

    for(i = 0; i < NUM_ROWS; ++i)
    {
        for(j = 0; j < NUM_COLS; ++j)
        {
            *(*(p_iArray + i) + j) = (i + 1) * (j + 1);
            printf("*(*(p_iArray + %d) + %d) = %d \t (*(p_iArray + %d) + %d) = %p\n", i, j, *(*(p_iArray + i) + j), i, j, (*(p_iArray + i) + j));
        }
    }

    printf("\n\n");
    printf("Cleanup:\n");
    for(i = NUM_ROWS - 1; i >= 0; --i)
    {
        if(p_iArray[i])
        {
            free(p_iArray[i]);
            p_iArray[i] = NULL;
            printf("Row %d memory freed...\n", i + 1);
        }
    }

    printf("\n");
    return 0;
}