#include <stdio.h>

int main(void)
{
    // variables
    double num;
    double *ptr = NULL;

    // code
    printf("\n\n");
    printf("Before ptr = &num\n");
    num = 12.234;
    printf("Value of num = %lf\n", num);
    printf("Address of num = %p\n", &num);
    printf("Value at address of num = %lf\n", *(&num));

    printf("\n\n");
    printf("After ptr = &num\n");
    ptr = &num;
    printf("Value of num = %lf\n", num);
    printf("Address of num = %p\n", ptr);
    printf("Value at address of num = %lf\n", *ptr);

    printf("\n");
    return 0;
}