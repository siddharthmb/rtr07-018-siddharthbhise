#include <stdio.h>

int main(void)
{
    // variables
    int num = 234;
    const int* const ptr = &num;

    // code
    printf("\n\n");
    printf("Current value of num = %d\n", num);
    printf("Current ptr = %p\n", ptr);

    num++;
    printf("After post-incrementing num, num = %d\n", num);
    printf("Trying to change the value of num through the pointer ptr, gives error! \n[[ConstPtrToConstInt.c(16): error C2166: l-value specifies const object]]\n");

    printf("\n");
    return 0;
}