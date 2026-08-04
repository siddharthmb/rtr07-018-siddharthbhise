#include <stdio.h>

int main(void)
{
    // functions
    void MathOps(int, int, int *, int *, int *, int *, int *);

    // variables
    int a, b, answerSum, answerDiff, answerProd, answerQuotient, answerRemainder;

    // code
    printf("\n\n");
    printf("Enter value of a: ");
    scanf("%d", &a);
    printf("Enter value of b: ");
    scanf("%d", &b);

    MathOps(a, b, &answerSum, &answerDiff, &answerProd, &answerQuotient, &answerRemainder);
    printf("\n\n");
    printf("Results: \n");
    printf("\tSum        = %d\n", answerSum);
    printf("\tDifference = %d\n", answerDiff);
    printf("\tProduct    = %d\n", answerProd);
    printf("\tQuotient   = %d\n", answerQuotient);
    printf("\tRemainder  = %d\n", answerRemainder);

    printf("\n");
    return 0;
}

void MathOps(int a, int b, int *sum, int *diff, int *prod, int *quotient, int *remainder)
{
    // code
    *quotient = *remainder = 0;
    *sum = a + b;
    *diff = a - b;
    *prod = a * b;
    if(b != 0)
    {
        *quotient = a / b;
        *remainder = a % b;
    }    
}
