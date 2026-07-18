#include <stdio.h>

#define NUM_ROWS 5
#define NUM_COLS 3
#define DEPTH    2

int main(void)
{
    // variables
    int array3d[NUM_ROWS][NUM_COLS][DEPTH] = {
       {{13, 20}, {23, 56}, {56, 90}},
       {{3, 0}, {2, 5}, {6, 9}},
       {{53, 27}, {28, 36}, {59, 92}},
       {{73, 70}, {22, 52}, {16, 94}},
       {{83, 27}, {63, 46}, {56, 90}}
    };

    int array1d[NUM_ROWS * NUM_COLS * DEPTH];

    int i, j, k;

    // code
    printf("\n\n");

    for(i = 0; i < NUM_ROWS; ++i)
    {
        for(j = 0; j < NUM_COLS; ++j)
        {
            for(k = 0; k < DEPTH; ++k)
            {
                array1d[i * NUM_COLS * DEPTH + j * DEPTH + k] = array3d[i][j][k];
            }
        }
    }

    printf("---------- 3D Array ----------\n");
    for(i = 0; i < NUM_ROWS; ++i)
    {
        printf("\t=== ROW %d ===\n", i + 1);
        for(j = 0; j < NUM_COLS; ++j)
        {
            printf("COLUMN %d: ", j + 1);
            for(k = 0; k < DEPTH; ++k)
            {
                printf("array[%d][%d][%d] = %d ", i, j, k, array3d[i][j][k]);
            }
            printf("\n");
        }
        printf("\n\n");
    }

    printf("---------- 1D Array (converted from above 3D array) ----------\n");
    printf("array[] : ");
    for(i = 0; i < NUM_ROWS * NUM_COLS * DEPTH; ++i)
    {
        printf(" %d", array1d[i]);
    }
    printf("\n");

    printf("\n");
    return 0;
}