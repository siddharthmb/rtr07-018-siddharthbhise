#include <stdio.h>

int main(void)
{
    // variables
    int iArray[10];
    int i;

    // code
    printf("\n\n");
    printf("Elements of the integer array along with their addresses\n");
    for(i = 0; i < 10; ++i)
    {
        iArray[i] = i + 1;
        printf("iArray[%d] = %d\t&iArray[i] = %p\n", i, iArray[i], &iArray[i]);
    }

    printf("\n");
    return 0;
}