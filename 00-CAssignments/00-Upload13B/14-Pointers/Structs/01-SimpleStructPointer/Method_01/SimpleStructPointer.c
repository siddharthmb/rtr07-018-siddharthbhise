#include <stdio.h>
#include <stdlib.h>

struct MyData
{
    int i;
    float f;
    double d;
};

typedef struct MyData MyData;

int main(void)
{
    // variables
    int intSize, floatSize, doubleSize;
    int myDataSize;
    int sizeOfPtrToMyData;

    MyData *pData = NULL;

    // code
    printf("\n\n");
    pData = (MyData *)malloc(sizeof(MyData));
    if(pData == NULL)
    {
        printf("Failed to allocate memory of size %zu bytes\n", sizeof(MyData));
        exit(1);
    }

    (*pData).i = 34;
    (*pData).f = 3.14f;
    (*pData).d = 4.454;

    printf("(*pData).i = %d\n", (*pData).i);
    printf("(*pData).f = %f\n", (*pData).f);
    printf("(*pData).d = %lf\n", (*pData).d);

    printf("\n\n");
    intSize = sizeof((*pData).i);
    floatSize = sizeof((*pData).f);
    doubleSize = sizeof((*pData).d);

    printf("Sizes of data members in bytes are\n");
    printf("\ti = %d\n", intSize);
    printf("\tf = %d\n", floatSize);
    printf("\td = %d\n", doubleSize);

    printf("\n\n");
    myDataSize = sizeof(MyData);
    printf("Size of struct MyData in bytes is: %d\n", myDataSize);
    sizeOfPtrToMyData = sizeof(MyData *);
    printf("Size of pointer to struct MyData is: %d\n", sizeOfPtrToMyData);

    printf("\n\n");
    // cleanup...
    if(pData)
    {
        free(pData);
        pData = NULL;
        printf("Memory of pData freed...\n");
    }

    printf("\n");
    return 0;
}
