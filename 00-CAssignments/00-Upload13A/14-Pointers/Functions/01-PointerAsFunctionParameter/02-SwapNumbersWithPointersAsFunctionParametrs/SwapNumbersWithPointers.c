#include <stdio.h>

int main(void)
{
    // functions
    void swapIntegers(int *, int *);

    // variables
    int n1, n2;

    // code
    printf("\n\n");
    printf("Enter n1: ");
    scanf("%d", &n1);
    printf("Enter n2: ");
    scanf("%d", &n2);

    printf("***** BEFORE swapping *****\n");
    printf("Value of n1: %d\n", n1);
    printf("Value of n2: %d\n", n2);

    swapIntegers(&n1, &n2);

    printf("***** AFTER swapping *****\n");
    printf("Value of n1: %d\n", n1);
    printf("Value of n2: %d\n", n2);

    printf("\n");
    return 0;
}

void swapIntegers(int *a, int *b)
{
    // code
    int temp = *a;
    *a = *b;
    *b = temp;
}
