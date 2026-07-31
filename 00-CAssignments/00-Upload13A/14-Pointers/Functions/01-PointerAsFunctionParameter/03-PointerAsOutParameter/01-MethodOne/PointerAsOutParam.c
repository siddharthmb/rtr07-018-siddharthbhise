#include <stdio.h>

int main(void)
{
    // functions
    void MathOps(int, int, int *, int *, int *, int *, int *);

    // variables;
    int a, b;
    int sum, diff, product, quotient, remainder;

    // code
    printf("\n\n");
    printf("Enter value of a: ");
    scanf("%d", &a);
    printf("Enter value of b: ");
    scanf("%d", &b);

    MathOps(a, b, &sum, &diff, &product, &quotient, &remainder);

    printf("\n\n");
    printf("Sum        (a + b)  = %d\n", sum);
    printf("Difference (a - b)  = %d\n", diff);
    printf("Product    (a * b)  = %d\n", product);
    printf("Quotient   (a / b)  = %d\n", quotient);
    printf("Remainder  (a %% b) = %d\n", remainder);

    printf("\n");
    return 0;
}

void MathOps(int a, int b, int *sum, int *diff, int *product, int *quotient, int *remainder)
{
    // code
    *quotient = 0;
    *remainder = 0;

    *sum = a + b;
    *diff = a - b;
    *product = a * b;
    if(b != 0)
    {
        *quotient = a / b;
        *remainder = a % b;
    }
}
