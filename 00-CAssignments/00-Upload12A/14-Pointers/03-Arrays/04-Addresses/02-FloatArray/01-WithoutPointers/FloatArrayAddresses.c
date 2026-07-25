#include <stdio.h>

int main(void)
{
    // variables
    float fArray[10];
    int i;

    // code
    printf("\n\n");
    for(i = 0; i < 10; ++i)
    {
        fArray[i] = i * 3.14f;
        printf("fArray[%d] = %.2f \t &fArray[%d] = %p\n", i, fArray[i], i, &fArray[i]);
    }

    printf("\n");
    return 0;
}