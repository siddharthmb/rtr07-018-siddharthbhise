#include <stdio.h>

struct MyData
{
    int    i;
    float  f;
    double d;
};

typedef struct MyData MyData;

int main(void)
{
    // variables
    MyData data;
    int iSize, fSize, dSize, structMyDataSize;

    // code
    printf("\n\n");
    data.i = 78;
    data.f = 2.45f;
    data.d = 6.123;

    printf("Displaying data members of the data variable of type MyData\n");
    printf("data.i = %d\n",  data.i);
    printf("data.f = %f\n",  data.f);
    printf("data.d = %lf\n", data.d);

    iSize = sizeof(data.i);
    fSize = sizeof(data.f);
    dSize = sizeof(data.d);
    structMyDataSize = sizeof(MyData);

    printf("Printing the sizes of types\n");
    printf("sizeof data.i = %d bytes\n", iSize);
    printf("sizeof data.f = %d bytes\n", fSize);
    printf("sizeof data.d = %d bytes\n", dSize);
    printf("sizeof MyData = %d bytes\n", structMyDataSize);


    printf("\n");
    return 0;
}