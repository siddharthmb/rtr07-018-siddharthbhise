#include <stdio.h>

#define NUM_ELEMENTS 10

int main(void)
{
    // variables
    int array[NUM_ELEMENTS];
    int i, j, count = 0;

    // code
    printf("\n\n");
    printf("Enter %d integer elements: ", NUM_ELEMENTS);
    for(i = 0; i < NUM_ELEMENTS; ++i)
    {
        scanf("%d", &array[i]);
        if(array[i] < 0) array[i] = array[i] * -1;
    }

    printf("\n\n");
    printf("Array elements are: ");
    for(i = 0; i < NUM_ELEMENTS; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n\n");
    printf("Prime numbers in the array are: ");
    for(i = 0; i < NUM_ELEMENTS; ++i)
    {
        if(array[i] == 1) continue;

        count = 0;
        for(j = 1; j <= array[i]; ++j)
        {
            if(array[i] % j == 0) ++count;
        }

        if(count == 2)  // for prime numbers, this will be exactly 2
        {
            printf("%d ", array[i]);
        }
    }

    printf("\n\n");

    return 0;
}