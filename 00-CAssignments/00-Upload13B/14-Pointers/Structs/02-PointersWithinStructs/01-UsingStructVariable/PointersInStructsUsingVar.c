#include <stdio.h>
#include <stdlib.h>

struct Data
{
    int *p_int;
    int i;

    float *p_float;
    float f;

    double *p_double;
    double d;
};

typedef struct Data Data;

int main(void)
{
    // variables
    Data data;

    // code
    printf("\n\n");
    data.i = 234;
    data.p_int = &data.i;

    data.f = 3.14f;
    data.p_float = &data.f;

    data.d = 7.231;
    data.p_double = &data.d;

    printf("data.i = %d \t &data.i = %p\n", data.i, data.p_int);
    printf("data.f = %.4f \t &data.f = %p\n", data.f, data.p_float);
    printf("data.i = %.4lf \t &data.d = %p\n", data.d, data.p_double);

    printf("\n");
    return 0;
}