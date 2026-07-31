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
    int intSize, floatSize, doubleSize, myDataSize, ptrToMyDataSize;
    MyData *pMyData = NULL;

    // code
    printf("\n\n");
    pMyData = (MyData *)malloc(sizeof(MyData));
    if(pMyData == NULL)
    {
        printf("Failed to allocate memory of %zu bytes\n", sizeof(MyData));
        exit(1);
    }

    pMyData->i = 87;
    pMyData->f = 7.987f;
    pMyData->d = 5.678;

    printf("Data members of pMyData of type MyData are\n");
    printf("pMyData->i = %d\n", pMyData->i);
    printf("pMyData->f = %.4f\n", pMyData->f);
    printf("pMyData->i = %.4lf\n", pMyData->d);

    printf("\n\n");

    intSize = sizeof(pMyData->i);
    floatSize = sizeof(pMyData->f);
    doubleSize = sizeof(pMyData->d);
    myDataSize = sizeof(*pMyData);
    ptrToMyDataSize = sizeof(pMyData);

    printf("Sizes in bytes of members, struct MyData and pointer to struct MyData are\n");
    printf("i = %d\n", intSize);
    printf("f = %d\n", floatSize);
    printf("d = %d\n", doubleSize);
    printf("MyData = %d\n", myDataSize);
    printf("(MyData *) = %d\n", ptrToMyDataSize);

    printf("\n\n");
    printf("Cleanup...");

    if(pMyData == NULL)
    {
        free(pMyData);
        pMyData = NULL;
        printf("Memory for pMyData freed!");
    }

    printf("\n");
    return 0;
}
