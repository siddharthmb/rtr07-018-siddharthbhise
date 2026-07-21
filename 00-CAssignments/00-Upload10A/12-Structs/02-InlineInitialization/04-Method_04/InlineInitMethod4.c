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
    MyData data1 = {35, 2.1f, 3.14, 'S'};
    MyData data2 = {'F', 2.1f, 3.14, 'S'};
    MyData data3 = {5};
    MyData data4 = {35, 'S'};

    printf("Printing members of all 4 data variables of type 'MyData'\n");
    printf("data1.i = %d\n",  data1.i);
    printf("data1.f = %f\n",  data1.f);
    printf("data1.d = %lf\n", data1.d);
    printf("data1.c = %c\n\n",  data1.c);

    printf("data2.i = %d\n",  data2.i);
    printf("data2.f = %f\n",  data2.f);
    printf("data2.d = %lf\n", data2.d);
    printf("data2.c = %c\n\n",  data2.c);

    printf("data3.i = %d\n",  data3.i);
    printf("data3.f = %f\n",  data3.f);
    printf("data3.d = %lf\n", data3.d);
    printf("data3.c = %c\n\n",  data3.c);

    printf("data4.i = %d\n",  data4.i);
    printf("data4.f = %f\n",  data4.f);
    printf("data4.d = %lf\n", data4.d);
    printf("data4.c = %c\n",  data4.c);

    printf("\n");
    return 0;
}