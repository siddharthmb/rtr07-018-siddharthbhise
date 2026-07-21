#include <stdio.h>

struct CharacterCount
{
    char ch;
    int count;
};

typedef struct CharacterCount CharacterCount;

int main(void)
{
    // variables
    CharacterCount charCountArray[26];
    int i, j;
    char str[100];
    char c;

    // code
    printf("\n\n");
    for(i = 0; i < 26; ++i)
    {
        charCountArray[i].ch = 65 + i;
        charCountArray[i].count = 0;
    }

    printf("Enter the string: ");
    gets_s(str, 100);

    for(i = 0; str[i] != '\0'; ++i)
    {
        c = toupper(str[i]);
        for(j = 0; j < 26; ++j)
        {
            if(charCountArray[j].ch == c)
            {
                charCountArray[j].count++;
                break;
            }
        }
    }

    printf("In the entered string %s, the below characters occur with mentioned count\n", str);
    for(i = 0; i < 26; ++i)
    {
        if(charCountArray[i].count > 0)
            printf("%c occurs %d times\n", charCountArray[i].ch, charCountArray[i].count);
    }

    printf("\n");
    return 0;
}