#include <stdio.h>

int main(void)
{
    // variables
    int num;
    int *ptr = NULL;
    int *copyptr = NULL;

    // code
    printf("\n\n");
    num = 123;
    ptr = &num;

    printf("BEFORE copyptr = ptr\n");
    printf("num     = %d\n", num);
    printf("&num    = %p\n", &num);
    printf("*(num)  = %d\n", *(&num));
    printf("ptr     = %p\n", ptr);
    printf("*ptr    = %d\n", *ptr);

    printf("\n\n");
    copyptr = ptr;
    printf("AFTER copyptr = ptr\n");
    printf("num         = %d\n", num);
    printf("&num        = %p\n", &num);
    printf("*(num)      = %d\n", *(&num));
    printf("ptr         = %p\n", ptr);
    printf("*ptr        = %d\n", *ptr);
    printf("copyptr     = %p\n", copyptr);
    printf("*copyptr    = %d\n", *copyptr);

    printf("\n");
    return 0;
}