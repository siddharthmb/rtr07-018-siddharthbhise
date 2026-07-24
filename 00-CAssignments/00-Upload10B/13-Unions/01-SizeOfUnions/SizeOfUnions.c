#include <stdio.h>

struct MyStruct
{
    int    i;
    float  f;
    double d;
    char   c;
};

union MyUnion
{
    int    i;
    float  f;
    double d;
    char   c;
};

typedef struct MyStruct MyStruct;
typedef union MyUnion   MyUnion;

int main(void)
{
    // code
    printf("\n\n");
    printf("Size of MyStruct = %zu\n", sizeof(MyStruct));
    printf("Size of MyUnion  = %zu\n", sizeof(MyUnion));

    printf("\n");
    return 0;
}