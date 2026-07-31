#include <stdio.h>

enum
{
    NEGATIVE = -1,
    ZERO,
    POSITIVE
};

int main(void)
{
    // functions
    int difference(int, int, int *);

    // variables
    int a, b, diff, ret;

    // code
    printf("\n\n");
    printf("Enter value of a: ");
    scanf("%d", &a);
    printf("Enter value of b: ");
    scanf("%d", &b);

    ret = difference(a, b, &diff);

    printf("Difference between %d and %d is %d, which is ", a, b, diff);
    switch(ret)
    {
        case NEGATIVE:
        printf("negative\n");
        break;
        case POSITIVE:
        printf("positive\n");
        break;
        case ZERO:
        printf("zero\n");
        break;
        default:
        break;
    }

    printf("\n");
    return 0;
}

int difference(int a, int b, int *diff)
{
    // code
    *diff = a - b;
    if(*diff < 0) return NEGATIVE;
    else if(*diff == 0) return ZERO;
    else return POSITIVE;
}
