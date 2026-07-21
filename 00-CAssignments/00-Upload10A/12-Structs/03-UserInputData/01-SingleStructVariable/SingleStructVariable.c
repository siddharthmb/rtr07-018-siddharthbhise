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
    printf("Enter value for i: ");
    scanf("%d", &data.i);
    printf("Enter value for f: ");
    scanf("%f", &data.f);
    printf("Enter value for d: ");
    scanf("%lf", &data.d);
    printf("Enter value for c: ");
    data.c = getch();

    printf("\nPrinting the user entered input values\n");
    printf("i = %d\n",  data.i);
    printf("f = %f\n",  data.f);
    printf("d = %lf\n", data.d);
    printf("c = %c\n",  data.c);

    printf("\n");
    return 0;
}