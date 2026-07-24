#include <stdio.h>

int main(void)
{
    // variables
    int num;
    int *ptr = NULL;

    // code
    printf("\n\n");

    num = 11;

    printf("***** Before assigning address of 'num' to ptr *****\n");
    printf("Value of num            = %d\n", num);
    printf("Address of num          = %p\n", &num);
    printf("Value at address of num = %d\n", *(&num));

    printf("\n");
    ptr = &num;

    printf("***** After assinging address of 'num' to ptr *****\n");
    printf("Value of num            = %d\n", num);
    printf("Address of num          = %p\n", ptr);
    printf("Value at address of num = %d\n", *ptr);

    printf("\n");
    return 0;
}