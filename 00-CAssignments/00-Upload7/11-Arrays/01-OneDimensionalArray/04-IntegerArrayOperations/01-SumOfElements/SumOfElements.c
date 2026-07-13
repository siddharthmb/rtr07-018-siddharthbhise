#include <stdio.h>

#define NUM_ELEMENTS 10

int main(void)
{
    // variables
    int array[NUM_ELEMENTS];
    int i, num, sum = 0;

    // code
    printf("\n\n");
    printf("Enter %d integer elements: ", NUM_ELEMENTS);
    for(i = 0; i < NUM_ELEMENTS; ++i)
    {
        scanf("%d", &array[i]);
    }

    for(i = 0; i < NUM_ELEMENTS; ++i)
    {
        sum = sum + array[i];
    }

    printf("\n\n");
    printf("Sum of all elements: %d\n", sum);

    return 0;
}