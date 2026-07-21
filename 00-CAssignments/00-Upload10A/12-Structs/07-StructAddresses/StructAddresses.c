#include <stdio.h>

struct MyData
{
    int    i;
    float  f;
    double d;
    char   c;
};

typedef struct MyData MyData;

int main(void)
{
    // variables
    MyData data;

    // code
    printf("\n\n");
    data.i = 23;
    data.f = 4.154f;
    data.d = 4.4565;
    data.c = 'x';

    printf("Members values are\n");
    printf("data.i = %d\n",  data.i);
    printf("data.f = %f\n",  data.f);
    printf("data.d = %lf\n", data.d);
    printf("data.c = %c\n",  data.c);

    printf("\n\n");
    printf("Addresses of data members of 'data' are\n");
    
    printf("&data.i = %p\n", &data.i);
    printf("&data.f = %p\n", &data.f);
    printf("&data.d = %p\n", &data.d);
    printf("&data.c = %p\n", &data.c);

    printf("Starting address of the 'data' variable = %p\n", &data);

    printf("\n");
    return 0;
}