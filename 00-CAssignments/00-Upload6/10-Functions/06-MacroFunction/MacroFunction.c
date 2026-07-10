#include <stdio.h>

#define MAX(a, b) ((a <= b) ? b : a)

int main(void)
{
    // variables
    int num1, num2;
    float f1, f2;

    // code
    printf("\n\n");
    printf("Enter a number: ");
    scanf("%d", &num1);
    printf("Enter another number: ");
    scanf("%d", &num2);

    printf("Max of %d and %d (ints) is %d\n", num1, num2, MAX(num1, num2));

    printf("Enter a float number: ");
    scanf("%f", &f1);
    printf("Enter another float number: ");
    scanf("%f", &f2);

    printf("Max of %0.2f and %0.2f (floats) is %0.2f\n", f1, f2, MAX(f1, f2));

    printf("\n");
    return 0;
}