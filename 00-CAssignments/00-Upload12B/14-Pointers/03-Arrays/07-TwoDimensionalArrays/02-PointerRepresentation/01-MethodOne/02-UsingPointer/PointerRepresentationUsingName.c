#include <stdio.h>

#define NUM_ROWS 5
#define NUM_COLS 3

int main(void)
{
    // variables
    int iArray[NUM_ROWS][NUM_COLS];
    int i, j;
    int *p_iArray_Row = NULL;

    // code
    printf("\n\n");

    for(i = 0; i < NUM_ROWS; ++i)
    {
        p_iArray_Row = iArray[i];
        for(j = 0; j < NUM_COLS; ++j)
        {
            *(p_iArray_Row + j) = (i + 1) * (j + 1);
            printf("*(p_iArray_Row + %d) = %d \t (p_iArray_Row + %d) = %p\n", j, *(p_iArray_Row + j), j, (p_iArray_Row + j));
        }
    }

    printf("\n");
    return 0;
}