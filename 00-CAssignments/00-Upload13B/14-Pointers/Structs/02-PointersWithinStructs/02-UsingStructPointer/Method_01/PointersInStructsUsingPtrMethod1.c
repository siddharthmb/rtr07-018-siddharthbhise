#include <stdio.h>
#include <stdlib.h>

struct Data
{
    int *p_int;
    int i;

    float *p_float;
    float f;
    
    double *p_double;
    double d;
};

typedef struct Data Data;

int main(void)
{
    // variables
    Data *pData = NULL;

    // code
    printf("\n\n");
    pData = (Data *)malloc(sizeof(Data));
    if(pData == NULL)
    {
        printf("Failed to allocate %zu bytes", sizeof(Data));
        exit(1);
    }

    (*pData).i = 23;
    (*pData).p_int = &(*pData).i;
    (*pData).f = 3.14f;
    (*pData).p_float = &(*pData).f;
    (*pData).d = 9.008;
    (*pData).p_double = &(*pData).d;

    printf("(*pData).i = %d \t (*pData).p_int    = %p\n", (*pData).i, (*pData).p_int);
    printf("(*pData).f = %.4f \t (*pData).p_float  = %p\n", (*pData).f, (*pData).p_float);
    printf("(*pData).d = %.4lf \t (*pData).p_double = %p\n", (*pData).d, (*pData).p_double);

    // cleanup
    printf("\n\n");
    printf("Cleanup...");
    if(pData)
    {
        free(pData);
        pData = NULL;
        printf("Freed bytes allocated to pData\n");
    }

    printf("\n");
    return 0;
}
