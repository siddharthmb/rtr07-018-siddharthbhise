#include <stdio.h>

int main(void)
{
    // defining the struct
    struct MyData
    {
        int    i;
        float  f;
        double d;
    } data;

    // variables
    int iSize, fSize, dSize, structMyDataSize;
    
    // code
    printf("\n\n");
    data.i = 40;
    data.f = 6.123f;
    data.d = 9.123;

    printf("Printing members of data\n");
    printf("data.i = %d\n", data.i);
    printf("data.f = %f\n", data.f);
    printf("data.d = %lf\n", data.d);

    iSize = sizeof(data.i);
    fSize = sizeof(data.f);
    dSize = sizeof(data.d);

    printf("Printing sizes of types\n");
    printf("data.i size = %d bytes\n", iSize);
    printf("data.f size = %d bytes\n", fSize);
    printf("data.d size = %d bytes\n", dSize);
    printf("\n");
    structMyDataSize = sizeof(struct MyData);
    printf("struct MyData size = %d bytes\n", structMyDataSize);

    printf("\n");
    return 0;
}