#include <stdio.h>

int main(void)
{
    // variables
    double num;
    double* ptr;

    // code
    printf("\n\n");
    num = 123.213;
    printf("BEFORE ptr = &num\n");
    printf("Value of num = %lf\n", num);
    printf("Address of num = %p\n", &num);
    printf("Value at address of num = %lf\n", *(&num));

    ptr = &num;
    printf("\n\nAFTER ptr = &num\n");
    printf("Value of num = %lf\n", num);
    printf("Address of num = %p\n", ptr);
    printf("Value at address of num = %lf\n", *ptr);

    printf("\n");
    return 0;
}