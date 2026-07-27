#include <stdio.h>

#define NUM_ROWS 5
#define NUM_COLS 3

int main(void)
{
    // variables
    int iArray[NUM_ROWS][NUM_COLS];
    int i, j;

    // code
    printf("\n\n");

    for(i = 0; i < NUM_ROWS; ++i)
    {
        for(j = 0; j < NUM_COLS; ++j)
        {
            *(iArray[i] + j) = (i + 1) * (j + 1);
            printf("*(iArray[%d] + %d) = %d \t (iArray[%d] + %d) = %p\n", i, j, *(iArray[i] + j), i, j, (iArray[i] + j));
        }
    }

    printf("\n");
    return 0;
}