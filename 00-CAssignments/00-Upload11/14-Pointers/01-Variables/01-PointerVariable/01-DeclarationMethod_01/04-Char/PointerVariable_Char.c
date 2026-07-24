#include <stdio.h>

int main(void)
{
    // variables
    char ch;
    char *ptr = NULL;

    // code
    printf("\n\n");
    printf("Before ptr = &ch\n");
    ch = 'a';
    printf("Value of ch            = %c\n", ch);
    printf("Address of ch          = %p\n", &ch);
    printf("value at address of ch = %c\n", *(&ch));

    printf("\n\nAfter ptr = &ch\n");
    ptr = &ch;
    printf("Value of ch            = %c\n", ch);
    printf("Address of ch          = %p\n", ptr);
    printf("value at address of ch = %c\n", *ptr);

    printf("\n");
    return 0;
}