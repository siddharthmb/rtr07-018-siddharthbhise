#include <stdio.h>

int main(void)
{
    // variables
    int num = 12334;
    int* const ptr = &num;

    // code
    printf("\n\n");
    printf("Current value of num = %d\n", num);
    printf("Current ptr which is address of num = %p\n", ptr);

    num++;
    printf("\n\n");
    printf("After post-incrementing num, num = %d\n", num);
    (*ptr)++;
    printf("(*ptr)++ makes the value %d\n", num);
    printf("*ptr = %d\n", *ptr);

    printf("\n");
    return 0;
}