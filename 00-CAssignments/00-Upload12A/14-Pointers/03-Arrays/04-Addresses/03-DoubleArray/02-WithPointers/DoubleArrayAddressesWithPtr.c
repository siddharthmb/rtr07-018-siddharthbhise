#include <stdio.h>

int main(void)
{
    // variables
    double dArray[10];
    double *p_dArray = dArray;
    int i;

    // code
    printf("\n\n");

    for(i = 0; i < 10; ++i)
    {
        *(p_dArray + i) = i * 2.5;
        printf("*(p_dArray + %d) = %lf \t (p_dArray + %d) = %p\n", i, *(p_dArray + i), i, (p_dArray + i));
    }

    printf("\n");
    return 0;
}