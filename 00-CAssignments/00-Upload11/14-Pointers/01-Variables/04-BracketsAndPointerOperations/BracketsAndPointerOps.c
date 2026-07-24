#include <stdio.h>

int main(void)
{
    // variables
    int num;
    int *ptr = NULL;
    int ans;

    // code
    printf("\n\n");
    num = 234;
    ptr = &num;

    printf("num     = %d\n", num);
    printf("&num    = %p\n", &num);
    printf("*(&num) = %d\n", *(&num));
    printf("ptr     = %p\n", ptr);
    printf("*ptr    = %d\n", *ptr);

    printf("Answer of (ptr + 10) = %p\n", (ptr + 10));
    printf("Answer of *(ptr + 10) = %d\n", *(ptr + 10));
    printf("Answer of (*ptr + 10) = %d\n", (*ptr + 10));

    ++*ptr;
    printf("Answer after ++*ptr = %d\n", *ptr);
    printf("Answer of *ptr++ = %d\n", *ptr++);

    ptr = &num;
    printf("Answer of (*ptr)++) = %d\n", *(ptr)++);

    printf("\n");
    return 0;
}