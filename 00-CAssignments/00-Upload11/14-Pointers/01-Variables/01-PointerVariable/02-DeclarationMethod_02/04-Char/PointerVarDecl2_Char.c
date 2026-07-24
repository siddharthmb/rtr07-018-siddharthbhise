#include <stdio.h>

int main(void)
{
    // variables
    char ch = 'A';
    char* ptr = NULL;

    // code
    printf("\n\n");
    printf("BEFORE ptr = &ch\n");
    printf("Value of ch = %c\n", ch);
    printf("Address of ch = %p\n", &ch);
    printf("Value at address of ch = %c\n", *(&ch));

    printf("\n\n");
    ptr = &ch;
    printf("Value of ch = %c\n", ch);
    printf("Address of ch = %p\n", ptr);
    printf("Value at address of ch = %c\n", *ptr);

    printf("\n");
    return 0;
}