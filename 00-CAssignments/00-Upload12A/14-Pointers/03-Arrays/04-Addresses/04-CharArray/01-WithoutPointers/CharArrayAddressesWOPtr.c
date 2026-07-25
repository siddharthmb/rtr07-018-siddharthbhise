#include <stdio.h>

int main(void)
{
    // variables
    char cArray[26];
    int i;

    // code
    printf("\n\n");
    for(i = 0; i < 26; ++i)
    {
        cArray[i] = 65 + i;
        printf("cArray[%d] = %c \t &cArray[%d] = %p\n", i, cArray[i], i, &cArray[i]);
    }

    printf("\n");
    return 0;
}