#include <stdio.h>

int main(void)
{
    // variables
    float fArray[10];
    float *f_ptrArray = fArray;
    int i;

    // code
    printf("\n\n");

    for(i = 0; i < 10; ++i)
    {
        fArray[i] = i * 3.14f;
        printf("*(f_ptrArray + %d) = %.2f \t (f_ptrArray + %d) = %p\n", i, *(f_ptrArray + i), i, (f_ptrArray + i));
    }

    printf("\n");
    return 0;
}