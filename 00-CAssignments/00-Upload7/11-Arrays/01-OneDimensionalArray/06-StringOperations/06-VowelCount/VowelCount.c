#include <stdio.h>

#define MAX_LEN 512

int main(void)
{
    // functions
    int smbstrlen(char[]);

    // variables
    char charArray1[MAX_LEN];
    int length = 0, i;
    int countA = 0;
    int countE = 0;
    int countI = 0;
    int countO = 0;
    int countU = 0;

    // code
    printf("\n\n");
    printf("Enter the string: ");
    gets_s(charArray1, MAX_LEN);

    length = smbstrlen(charArray1);
    for(i = 0; i < length; ++i)
    {
        switch(charArray1[i])
        {
        case 'a':
        case 'A':
        ++countA;
        break;
        case 'E':
        case 'e':
        ++countE;
        break;
        case 'o':
        case 'O':
        ++countO;
        break;
        case 'i':
        case 'I':
        ++countI;
        break;
        case 'u':
        case 'U':
        ++countU;
        break;
        default:
        break;
        }
    }

    printf("In the entered string '%s', below is the count per vowel\n", charArray1);
    printf("A = %d\tE = %d\tO = %d\tI = %d\tU = %d\n", countA, countE, countO, countI, countU);

    return 0;
}

int smbstrlen(char s[])
{
    int i = 0;
    while(s[i] != '\0')
    {
        ++i;
    }

    return i;
}
