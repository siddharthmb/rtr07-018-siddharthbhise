#include <stdio.h>

int main(void)
{
    // variables
    char cArray[26];
    char *p_cArray = cArray;
    int i;

    // code
    printf("\n\n");
    for(i = 0; i < 26; ++i)
    {
        *(p_cArray + i) = 97 + i;
        printf("*(p_cArray + %d) = %c \t (p_cArray + %d) = %p\n", i, *(p_cArray + i), i, (p_cArray + i));
    }

    printf("\n");
    return 0;
}