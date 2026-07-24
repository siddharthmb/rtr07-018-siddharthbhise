#include <stdio.h>

int main(void)
{
    // variables
    float num;
    float* ptr = NULL;

    // code
    printf("\n\n");
    num = 234.7652f;
    printf("BEFORE ptr = &num\n");
    printf("Value of num = %f\n", num);
    printf("Address of num = %p\n", &num);
    printf("Value at address of num = %f\n", *(&num));

    printf("AFTER ptr = &num\n");
    ptr = &num;
    printf("Value of num = %f\n", num);
    printf("Address of num = %p\n", ptr);
    printf("Value at address of num = %f\n", *ptr);

    printf("\n");
    return 0;
}