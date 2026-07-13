#include <stdio.h>

#define INT_ARRAY_MAX_ELEMENTS   5
#define FLOAT_ARRAY_MAX_ELEMENTS 3
#define CHAR_ARRAY_MAX_ELEMENTS  15

int main(void)
{
    // variables
    int arrayOfInts[INT_ARRAY_MAX_ELEMENTS];
    float arrayOfFloats[FLOAT_ARRAY_MAX_ELEMENTS];
    char arrayOfChars[CHAR_ARRAY_MAX_ELEMENTS];
    int i, num;

    // code
    printf("\n\n");
    printf("Enter the integers: \n");
    for(i = 0; i < INT_ARRAY_MAX_ELEMENTS; ++i)
    {
        scanf("%d", &arrayOfInts[i]);
    }
    printf("Integer array entered by you : ");
    for(i = 0; i < INT_ARRAY_MAX_ELEMENTS; ++i)
    {
        printf("%d ", arrayOfInts[i]);
    }

    printf("\n\n");
    printf("Enter the characters: \n");
    for(i = 0; i < CHAR_ARRAY_MAX_ELEMENTS; ++i)
    {
        scanf("%c", &arrayOfChars[i]);
    }
    printf("Character array entered by you : ");
    for(i = 0; i < CHAR_ARRAY_MAX_ELEMENTS; ++i)
    {
        printf("%c ", arrayOfChars[i]);
    }

    printf("\n\n");
    printf("Enter the floats: \n");
    for(i = 0; i < FLOAT_ARRAY_MAX_ELEMENTS; ++i)
    {
        scanf("%f", &arrayOfFloats[i]);
    }
    printf("Float array entered by you : ");
    for(i = 0; i < FLOAT_ARRAY_MAX_ELEMENTS; ++i)
    {
        printf("%f ", arrayOfFloats[i]);
    }

    return 0;
}