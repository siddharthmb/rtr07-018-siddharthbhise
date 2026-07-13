#include <stdio.h>

#define MAX_LEN 512

int main(void)
{
    // functions
    char smbtoupper(char);

    // variables
    char string1[MAX_LEN], stringcapital[MAX_LEN];
    int length, i, j, capme = 1;

    // code
    printf("\n\n");
    printf("Enter a string: ");
    gets_s(string1, MAX_LEN);
    length = strlen(string1);
    for(i = 0, j = 0; i < length; ++i)
    {
        if(capme)
        {
            capme = 0;
            stringcapital[j++] = smbtoupper(string1[i]);
        }
        else
        {
            stringcapital[j++] = string1[i];
        }

        switch(string1[i])
        {
            case ' ':
            capme = 1;
            break;
            default:
            break;
        }
    }

    printf("String original: %s\n", string1);
    printf("Capitalized string: %s\n", stringcapital);

    return 0;
}

char smbtoupper(char c)
{
    if(c >= 97 && c <= 122) c = c - 32;

    return c;
}
