#include <stdio.h>

int main(void)
{
    // variables
    int num;
    int* ptr = NULL;

    // code
    printf("\n\n");

    num = 10;
    printf("BEFORE ptr = &num\n");
    printf("Value of num = %d\n", num);
    printf("Address of num = %p\n", &num);
    printf("Value at address of num = %d\n", *(&num));

    printf("\n");
    printf("AFTER ptr = &num\n");
    ptr = &num;
    printf("Value of num = %d\n", num);
    printf("Address of num = %p\n", ptr);
    printf("Value at addresse of num = %d\n", *ptr);

    printf("\n");
    return 0;
}