#include <stdio.h>

struct MyData
{
    int     i;
    float   f;
    double  d;
    char    c;
} data;     // global variable 'data'

int main(void)
{
    // variables
    int iSize;
    int fSize;
    int dSize;
    int structMyDataSize;
    
    // code
    printf("\n\n");

    data.i = 20;
    data.f = 3.1415f;
    data.d = 6.28;
    data.c = 'B';

    printf("Printing variable data's members\n");
    printf("data.i = %2d\n", data.i);
    printf("data.f = %2f\n", data.f);
    printf("data.d = %2lf\n", data.d);
    printf("data.c = %2c\n", data.c);

    printf("\n");
    iSize = sizeof(data.i);
    fSize = sizeof(data.f);
    dSize = sizeof(data.d);

    printf("Printing sizes of various data types along with our struct\n");
    printf("sizeof(i) which is int    = %d bytes\n", iSize);
    printf("sizeof(f) which is float  = %d bytes\n", fSize);
    printf("sizeof(d) which is double = %d bytes\n", dSize);
    printf("sizeof(c) which is char   = %d bytes\n", (int)sizeof(data.c));

    printf("\n\n");
    structMyDataSize = sizeof(struct MyData);
    printf("sizeof(struct MyData) = %d bytes\n", structMyDataSize);
    
    printf("\n");
    return 0;
}