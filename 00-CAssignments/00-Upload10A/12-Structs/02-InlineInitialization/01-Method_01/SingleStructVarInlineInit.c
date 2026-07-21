#include <stdio.h>

struct MyData
{
    int    i;
    float  f;
    double d;
    char   c;
} data = {25, 3.14f, 6.28, 'B'};

int main(void)
{
    // code
    printf("\n\n");
    printf("Printing data members of variable 'data' of type 'MyData'\n");
    printf("data.i = %d\n",  data.i);
    printf("data.f = %f\n",  data.f);
    printf("data.d = %lf\n", data.d);
    printf("data.c = %c\n",  data.c);

    printf("\n");
    return 0;
}