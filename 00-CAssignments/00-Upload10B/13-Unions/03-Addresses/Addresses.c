#include <stdio.h>

struct MyStruct
{
    int    i;
    float  f;
    double d;
    char   c;
};

typedef struct MyStruct MyStruct;

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
    MyStruct s;
    MyUnion  u;

    // code
    printf("\n\n");

    s.i = 10;
    s.f = 0.78f;
    s.d = 10.0;
    s.c = 'S';

    printf("Addresses of s (type of MyStruct) members\n");
    printf("&s.i = %p\n", &s.i);
    printf("&s.f = %p\n", &s.f);
    printf("&s.d = %p\n", &s.d);
    printf("&s.c = %p\n", &s.c);

    printf("\n\n");

    u.i = 2;
    u.f = 3.092f;
    u.d = 1.0;
    u.c = 'X';

    printf("Addresses of u (type of MyUnion) members\n");
    printf("&u.i = %p\n", &u.i);
    printf("&u.f = %p\n", &u.f);
    printf("&u.d = %p\n", &u.d);
    printf("&u.c = %p\n", &u.c);

    printf("\n");
    return 0;
}