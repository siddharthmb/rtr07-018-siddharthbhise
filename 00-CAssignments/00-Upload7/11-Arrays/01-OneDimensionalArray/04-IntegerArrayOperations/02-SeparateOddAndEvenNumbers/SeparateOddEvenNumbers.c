#include <stdio.h>

#define NUM_ELEMENTS 10

int main(void)
{
    // variables
    int array[NUM_ELEMENTS];
    int i, sum = 0;

    // code
    printf("\n\n");
    printf("Enter %d integer elements: ", NUM_ELEMENTS);
    for(i = 0; i < NUM_ELEMENTS; ++i)
    {
        scanf("%d", &array[i]);
    }

    printf("\n\n");
    printf("Odd numbers in the array are: ");
    for(i = 0; i < NUM_ELEMENTS; ++i)
    {
        if(array[i] % 2 != 0)
        {
            printf("%d ", array[i]);
        }
    }

    printf("\n\n");
    printf("Even numbers in the array are: ");
    for(i = 0; i < NUM_ELEMENTS; ++i)
    {
        if(array[i] % 2 == 0)
        {
            printf("%d ", array[i]);
        }
    }

    printf("\n\n");

    return 0;
}