#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLS 3

int main(void)
{
    // variables
    int **p_iArray = NULL;
    int i, j;
    
    // code
    printf("\n\n");
    p_iArray = (int **)malloc(sizeof(int *) * NUM_ROWS);
    if(p_iArray == NULL)
    {
        printf("Failed to allocate int ** of %zu bytes\n", sizeof(int *) * NUM_ROWS);
        exit(1);
    }

    // allocating memory for each row
    for(i = 0; i < NUM_ROWS; ++i)
    {
        p_iArray[i] = (int *)malloc(sizeof(int) * NUM_COLS);
        if(p_iArray[i] == NULL)
        {
            printf("Failed to allocate %zu bytes for row %d\n", sizeof(int) * NUM_COLS, i + 1);
            exit(1);
        }
    }

    // assigning values
    for(i = 0; i < NUM_ROWS; ++i)
    {
        printf("Row %d (@%p, @@%p) : ", i + 1, p_iArray[i], &p_iArray[i]);
        for(j = 0; j < NUM_COLS; ++j)
        {
            p_iArray[i][j] = (i + 1) * (j + 1);
            printf("<p_iArray[%d][%d] = %d, %p> ", i, j, p_iArray[i][j], &p_iArray[i][j]);
        }
        printf("\n");
    }
    
    printf("\n\n");
    printf("Cleanup...\n");
    for(i = NUM_ROWS - 1; i >= 0; --i)
    {
        if(p_iArray[i])
        {
            free(p_iArray[i]);
            p_iArray[i] = NULL;
            printf("Row %d freed...\n", i + 1);
        }
    }

    printf("\n");
    if(p_iArray)
    {
        free(p_iArray);
        p_iArray = NULL;
        printf("p_iArray (type int **), freed...\n");
    }    

    printf("\n");
    return 0;
}