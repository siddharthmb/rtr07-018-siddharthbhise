#include <stdio.h>

int main(void)
{
    // variables
    int num = 555;
    int *ptr = NULL;
    int **pptr = NULL;

    // code
    printf("\n\n");
    printf("***** BEFORE ptr = &num *****\n");
    printf("num = %d \t &num = %p \t *(&num) = %d\n", num, &num, *(&num));

    ptr = &num;

    printf("\n\n");
    printf("***** AFTER ptr = &num *****\n");
    printf("num = %d \t ptr = %p \t *ptr = %d\n", num, ptr, *ptr);

    pptr = &ptr;
    printf("\n\n");
    printf("***** AFTER pptr = &ptr *****\n");
    printf("value of num = %d\n", num);
    printf("Address of num (ptr) = %p\n", ptr);
    printf("Address of ptr itself = %p\n", pptr);
    printf("Value at address of ptr (*pptr) = %p", *pptr);
    printf("Value at address of num, which is *ptr AND also **pptr = %d\n", **pptr);

    printf("\n");
    return 0;
}