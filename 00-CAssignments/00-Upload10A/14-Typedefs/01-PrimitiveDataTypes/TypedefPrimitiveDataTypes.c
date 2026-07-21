#include <stdio.h>

typedef int MYINT;

int main(void)
{
    // typedefs
    typedef float  MYFLOAT;
    typedef double MYDOUBLE;
    typedef char   MYCHAR;

    // variables
    MYINT    i[] = {1, 2, 3};
    MYFLOAT  f[] = {1.1f, 2.2f, 3.3f};
    MYDOUBLE d[] = {2.2, 4.4, 6.6};
    MYCHAR   c[] = {'a', 'b', 'c'};

    MYINT j;

    // code
    printf("\n\n");
    for(j = 0; j < 3; ++j)
    {
        printf("i[%d] = %2d\n",    j, i[j]);
        printf("f[%d] = %2.1f\n",  j, f[j]);
        printf("d[%d] = %2.3lf\n", j, d[j]);
        printf("c[%d] = %2c\n",    j, c[j]);
        printf("\n");
    }

    printf("\n");
    return 0;
}