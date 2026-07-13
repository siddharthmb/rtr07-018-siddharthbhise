#include <stdio.h>

int main(void)
{
    // variables
    char chArray1[] = {'A', 'S', 'T', 'R', 'O', 'M', 'E', 'D', 'I', 'C', 'O', 'M', 'P', '\0'};
    char chArray2[] = {'W', 'E', 'L', 'C', 'O', 'M', 'E', 'S', '\0'};
    char chArray3[] = {'Y', 'O', 'U', '\0'};
    char chArray4[] = "To";
    char chArray5[] = "Real Time Rendering, Batch of 2026-27";
    char chWithoutNullTerminator[] = {'A', 'E', 'I', 'O', 'U'};

    // code
    printf("\n\n");
    printf("Size of chArray1 = %zu\n", sizeof(chArray1));
    printf("Size of chArray2 = %zu\n", sizeof(chArray2));
    printf("Size of chArray3 = %zu\n", sizeof(chArray3));
    printf("Size of chArray4 = %zu\n", sizeof(chArray4));
    printf("Size of chArray5 = %zu\n", sizeof(chArray5));

    printf("\n\n");
    printf("The strings are: \n\n");
    printf("chArray1 : %s\n", chArray1);
    printf("chArray2 : %s\n", chArray2);
    printf("chArray3 : %s\n", chArray3);
    printf("chArray4 : %s\n", chArray4);
    printf("chArray5 : %s\n", chArray5);

    printf("\n\n");
    printf("Size of character array without null teminator: %zu\n", sizeof(chWithoutNullTerminator));
    printf("chWithoutNullTerminator: %s\n", chWithoutNullTerminator);

    return 0;
}