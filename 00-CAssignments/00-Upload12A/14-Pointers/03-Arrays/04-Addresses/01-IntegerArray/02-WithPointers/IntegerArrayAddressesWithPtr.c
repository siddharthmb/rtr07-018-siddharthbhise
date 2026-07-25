#include <stdio.h>

int main(void)
{
    // variables
    int iArray[10];
    int *ptr_iArray = iArray;
    int i;

    // code
    printf("\n\n");
    printf("Printing the integer array elements and their addresses using pointer\n")
    for(i = 0; i < 10; i++)
    {
        iArray[i] = i + 1;
        printf("*(ptr_iArray + %d) = %d \t (ptr_iArray + %d) = %p\n", i, *(ptr_iArray + i), i, (ptr_iArray + i));
    }

    printf("\n");
    return 0;
}