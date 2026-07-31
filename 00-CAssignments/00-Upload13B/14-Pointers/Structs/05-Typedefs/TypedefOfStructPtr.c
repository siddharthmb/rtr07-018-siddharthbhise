#include <stdio.h>
#include <stdlib.h>

struct Data
{
    int i;
    float f;
    double d;
};

typedef struct Data Data;
typedef Data * DataPtr;

int main(void)
{
    // variables;
    int intsize, floatsize, doublesize, datasize, ptrdatasize;
    Data d;
    DataPtr pData = &d;

    // code
    printf("\n\n");
    pData->i = 45;
    pData->f = 4.212f;
    pData->d = 3.14;
    intsize = sizeof(pData->i);
    floatsize = sizeof(pData->f);
    doublesize = sizeof(pData->d);
    datasize = sizeof(d);
    ptrdatasize = sizeof(pData);

    printf("pData->i = %d \t sizeof(pData->i) = %d\n", pData->i, intsize);
    printf("pData->f = %f \t sizeof(pData->f) = %d\n", pData->f, floatsize);
    printf("pData->d = %lf \t sizeof(pData->d) = %d\n", pData->d, doublesize);
    printf("\nsizeof(Data) = %d\n", datasize);
    printf("sizeof(pData) = %d\n", ptrdatasize);

    printf("\n");
    return 0;
}