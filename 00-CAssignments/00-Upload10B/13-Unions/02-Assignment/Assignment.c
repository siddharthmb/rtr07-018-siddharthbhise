#include <stdio.h>

union MyUnion
{
    int    i;
    float  f;
    double d;
    char   c;
};

typedef union MyUnion MyUnion;

int main(void)
{
    // variables
    MyUnion u1, u2;

    // code
    printf("\n\n");
    printf("Members of u1 are\n");

    u1.i = 23;
    u1.f = 3.14f;
    u1.d = 6.28;
    u1.c = 'S';

    printf("u1.i = %d\n" , u1.i);
    printf("u1.f = %f\n" , u1.f);
    printf("u1.d = %lf\n", u1.d);
    printf("u1.c = %c\n" , u1.c);

    printf("\n");
    printf("Below are the addresses of the members of u1\n");

    printf("&u1.i = %p\n" , &u1.i);
    printf("&u1.f = %p\n" , &u1.f);
    printf("&u1.d = %p\n",  &u1.d);
    printf("&u1.c = %p\n" , &u1.c);

    printf("\n\n");
    printf("Members of u2 are\n");

    u2.i = 56;
    u2.f = 6.7f;
    u2.d = 56.87;
    u2.c = 'F';

    printf("u2.i = %d\n" , u2.i);
    printf("u2.f = %f\n" , u2.f);
    printf("u2.d = %lf\n", u2.d);
    printf("u2.c = %c\n" , u2.c);

    printf("\n");
    printf("Below are the addresses of the members of u2\n");

    printf("&u2.i = %p\n" , &u2.i);
    printf("&u2.f = %p\n" , &u2.f);
    printf("&u2.d = %p\n",  &u2.d);
    printf("&u2.c = %p\n" , &u2.c);

    printf("\n");
    return 0;
}