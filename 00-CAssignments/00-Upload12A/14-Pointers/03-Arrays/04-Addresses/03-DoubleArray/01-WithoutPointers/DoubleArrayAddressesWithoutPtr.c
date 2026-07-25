#include <stdio.h>

int main(void)
{
    // variables
    double dArray[10];
    int i;

    // code
    printf("\n\n");

    for(i = 0; i < 10; ++i)
    {
        dArray[i] = i * 2.0f;
        printf("dArray[%d] = %lf \t &dArray[%d] = %p\n", i, dArray[i], i, &dArray[i]);
    }

    printf("\n");
    return 0;
}