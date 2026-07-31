#include <stdio.h>

int main(void)
{
    // functions
    void swapIntegers(int, int);

    // variables
    int num1, num2;

    // code
    printf("\n\n");

    printf("Enter num1: ");
    scanf("%d", &num1);

    printf("Enter num2: ");
    scanf("%d", &num2);

    printf("***** BEFORE swapping *****\n");
    printf("num1 = %d \t num2 = %d\n", num1, num2);
    swapIntegers(num1, num2);

    printf("\n\n");
    printf("***** AFTER swapping ***** \n");
    printf("num1 = %d \t num2 = %d\n", num1, num2);

    printf("\n");
    return 0;
}

void swapIntegers(int a, int b)
{
    int temp = b;

    printf("swapIntegers(): before swapping a = %d, b = %d\n", a, b);
    b = a;
    a = temp;
    printf("swapIntegers(): after  swapping a = %d, b = %d\n", a, b);
}
