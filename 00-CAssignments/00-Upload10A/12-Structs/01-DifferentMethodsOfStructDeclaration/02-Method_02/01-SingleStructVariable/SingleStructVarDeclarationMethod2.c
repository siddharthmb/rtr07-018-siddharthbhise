#include <stdio.h>

struct MyData
{
    int     i;
    float   f;
    double  d;
};

typedef struct MyData MyData;

MyData data;

int main(void)
{
    // variables
    int iSize, fSize, dSize;
    int structMyDataSize;

    // code
    printf("\n\n");

    data.i = 25;
    data.f = 5.5f;
    data.d = 8.0;

    printf("data.i = %d\n", data.i);
    printf("data.f = %f\n", data.f);
    printf("data.d = %lf\n", data.d);

    printf("Printing sizes of types\n");
    iSize = sizeof(data.i);
    fSize = sizeof(data.f);
    dSize = sizeof(data.d);

    printf("sizeof(data.i) = %d bytes\n", iSize);
    printf("sizeof(data.f) = %d bytes\n", fSize);
    printf("sizeof(data.d) = %d bytes\n", dSize);
    printf("\n");
    structMyDataSize = sizeof(MyData);
    printf("sizeof(struct MyData) = %d bytes\n", structMyDataSize);

    printf("\n");
    return 0;
}