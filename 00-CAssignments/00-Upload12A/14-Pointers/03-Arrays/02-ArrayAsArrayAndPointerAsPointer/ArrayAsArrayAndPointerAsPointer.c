#include <stdio.h>

int main(void)
{
    // variables
    int iArray[] = {10, 20, 30, 40};
    int *ptr_iArray = NULL;

    // code
    printf("\n\n");
    printf("iArray[0] = %d \t &iArray[0] = %p\n", iArray[0], &iArray[0]);
    printf("iArray[1] = %d \t &iArray[1] = %p\n", iArray[1], &iArray[1]);
    printf("iArray[2] = %d \t &iArray[2] = %p\n", iArray[2], &iArray[2]);
    printf("iArray[3] = %d \t &iArray[3] = %p\n", iArray[3], &iArray[3]);

    ptr_iArray = iArray;
    printf("*(ptr_iArray + 0) = %d \t (ptr_iArray + 0) = %p\n", *(ptr_iArray + 0), (ptr_iArray + 0));
    printf("*(ptr_iArray + 1) = %d \t (ptr_iArray + 1) = %p\n", *(ptr_iArray + 1), (ptr_iArray + 1));
    printf("*(ptr_iArray + 2) = %d \t (ptr_iArray + 2) = %p\n", *(ptr_iArray + 2), (ptr_iArray + 2));
    printf("*(ptr_iArray + 3) = %d \t (ptr_iArray + 3) = %p\n", *(ptr_iArray + 3), (ptr_iArray + 3));

    printf("\n");
    return 0;
}