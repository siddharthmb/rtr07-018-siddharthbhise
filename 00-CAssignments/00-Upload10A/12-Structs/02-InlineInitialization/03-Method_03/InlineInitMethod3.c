#include <stdio.h>

int main(void)
{
    // defining struct
    struct MyData
    {
        int    i;
        float  f;
        double d;
        char   c;
    } data = {68, 2.2f, 56.65, 'F'};

    // code
    printf("\n\n");
    printf("data.i = %d\n",  data.i);
    printf("data.f = %f\n",  data.f);
    printf("data.d = %lf\n", data.d);
    printf("data.c = %c\n",  data.c);

    printf("\n");
    return 0;
}