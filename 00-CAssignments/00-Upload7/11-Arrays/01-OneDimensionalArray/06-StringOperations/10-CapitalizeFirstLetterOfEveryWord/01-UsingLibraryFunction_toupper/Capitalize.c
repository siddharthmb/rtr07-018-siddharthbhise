#include <stdio.h>
#include <string.h>

#define MAX_LEN 512

int main(void)
{
    // variables
    char chArray[MAX_LEN], chChangedArray[MAX_LEN];
    int length, i, j;
    int capme = 1;

    // code
    printf("\n\n");
    printf("Enter a string: ");
    gets_s(chArray, MAX_LEN);

    length = strlen(chArray);
    for(j = 0, i = 0; i < length; ++i)
    {
        if(capme)
        {
            capme = 0;
            chChangedArray[j++] = toupper(chArray[i]);
        }
        else
        {
            chChangedArray[j++] = chArray[i];
        }
        
        switch(chArray[i])
        {
            case ' ':
            capme = 1;
            break;
            default:
            break;
        }
    }

    chChangedArray[j] = '\0';
    printf("Original string: %s\n", chArray);
    printf("Capitalized string: %s\n", chChangedArray);

    return 0;
}