#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // functions
    void MathOps(int, int, int *, int *, int *, int *, int *);

    // variables
    int a, b;
    int *sum       = NULL;
    int *diff      = NULL;
    int *prod      = NULL;
    int *quotient  = NULL;
    int *remainder = NULL;

    // code
    printf("\n\n");
    printf("Enter value of a: ");
    scanf("%d", &a);
    printf("Enter value of b: ");
    scanf("%d", &b);

    sum       = (int *)malloc(sizeof(int) * 1);
    diff      = (int *)malloc(sizeof(int) * 1);
    prod      = (int *)malloc(sizeof(int) * 1);
    quotient  = (int *)malloc(sizeof(int) * 1);
    remainder = (int *)malloc(sizeof(int) * 1);

    if(sum == NULL || diff == NULL || prod == NULL || quotient == NULL || remainder == NULL)
    {
        printf("Malloc failed!!\n");
        exit(1);
    }

    MathOps(a, b, sum, diff, prod, quotient, remainder);
    printf("\n\n");
    printf("Result: \n");
    printf("\tSum        = %d\n", *sum);
    printf("\tDifference = %d\n", *diff);
    printf("\tProduct    = %d\n", *prod);
    printf("\tQuotient   = %d\n", *quotient);
    printf("\tRemainder  = %d\n", *remainder);

    printf("\n\n");
    printf("Cleanup...\n");
    if(sum)
    {
        free(sum);
        sum = NULL;
        printf("Freed memory allocated for sum...\n");
    }
    if(diff)
    {
        free(diff);
        diff = NULL;
        printf("Freed memory allocated for diff...\n");
    }
    if(prod)
    {
        free(prod);
        prod = NULL;
        printf("Freed memory allocated for prod...\n");
    }
    if(quotient)
    {
        free(quotient);
        quotient = NULL;
        printf("Freed memory allocated for quotient...\n");
    }
    if(remainder)
    {
        free(remainder);
        remainder = NULL;
        printf("Freed memory allocated for remainder...\n");
    }

    printf("\n");
    return 0;
}

void MathOps(int a, int b, int *sum, int *diff, int *prod, int *quotient, int *remainder)
{
    *quotient = *remainder = 0;
    *sum  = a + b;
    *diff = a - b;
    *prod = a * b;
    if(b != 0)
    {
        *quotient  = a / b;
        *remainder = a % b;
    }
}
