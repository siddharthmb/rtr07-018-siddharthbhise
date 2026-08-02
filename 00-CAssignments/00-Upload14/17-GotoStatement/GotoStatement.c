#include <stdio.h>
#include <string.h>

int main(void)
{
    // variables
    char c, i;
    unsigned int ascii_c = 0;

    // code
    printf("\n\n");

    printf("Enter the First Character of your name: ");
    c = getch();
    printf("%c\n", c);

    for(i = 'A'; i <= 'Z'; ++i)
    {
        if(c == i)
        {
            ascii_c = (unsigned int)c;
            goto result;
        }
    }

    printf("Goto did not execute!\n");

result:
    if(ascii_c == 0)
    {
        printf("What on Earth is this %c character doing in a name?!\n", c);
    }
    else
    {
        printf("Character %c found at ascii = %d.\n", c, ascii_c);
    }

    printf("\n");
    return 0;
}