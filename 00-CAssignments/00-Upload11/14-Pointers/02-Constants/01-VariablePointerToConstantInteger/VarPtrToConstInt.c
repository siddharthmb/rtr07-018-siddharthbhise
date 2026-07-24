#include <stdio.h>

int main(void)
{
    // variables
    int num = 23423;
    const int *ptr = NULL;

    // code
    printf("\n\n");

    ptr = &num;
    printf("Current value of num = %d\n", num);
    printf("Current ptr which is address of num = %p\n", ptr);
    
    num = num * 10;
    printf("\n\n");
    printf("After num = num * 10, num = %d\n", num);

    ptr++;
    printf("\n\n");
    printf("After ptr++, value of ptr = %p\n", ptr);
    printf("Value at this new address of ptr = %d\n", *ptr);

    printf("\n");
    return 0;
}