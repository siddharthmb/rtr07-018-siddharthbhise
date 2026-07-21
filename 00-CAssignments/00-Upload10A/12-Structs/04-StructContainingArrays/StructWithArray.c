#include <stdio.h>

#define INT_ARRAY_SIZE   10
#define FLOAT_ARRAY_SIZE 5
#define CHAR_ARRAY_SIZE  26

#define NUM_STRINGS 3
#define MAX_CHARS_IN_STR 20

#define ALPHABET_BEGINNING 65

struct MyDataNumber
{
    int intArray[INT_ARRAY_SIZE];
    float floatArray[FLOAT_ARRAY_SIZE];
};

struct MyDataString
{
    char charArray[CHAR_ARRAY_SIZE];
    char strArray[NUM_STRINGS][MAX_CHARS_IN_STR];
};

typedef struct MyDataNumber MyDataNumber;
typedef struct MyDataString MyDataString;

int main(void)
{
    // variables
    MyDataNumber data1;
    MyDataString data2;
    int i;

    // code
    printf("\n\n");
    data1.floatArray[0] = 1.0f;
    data1.floatArray[1] = 2.0f;
    data1.floatArray[2] = 3.0f;
    data1.floatArray[3] = 4.0f;
    data1.floatArray[4] = 5.0f;

    printf("User input for integer array\n");
    for(i = 0; i < INT_ARRAY_SIZE; ++i)
    {
        scanf("%d", &data1.intArray[i]);
    }

    printf("Assigning values to character array using loop\n");
    for(i = 0; i < CHAR_ARRAY_SIZE; ++i)
    {
        data2.charArray[i] = (char)(i + ALPHABET_BEGINNING);
    }

    printf("Piecemeal assignment of string array\n");
    strcpy(data2.strArray[0], "Welcome");
    strcpy(data2.strArray[1], "To");
    strcpy(data2.strArray[2], "Astromedicomp RTR7.0!");

    printf("\n\n");
    printf("Integer array: ");
    for(i = 0; i < INT_ARRAY_SIZE; ++i)
        printf("%d ", data1.intArray[i]);

    printf("\n");
    printf("Float array: ");
    for(i = 0; i < FLOAT_ARRAY_SIZE; ++i)
        printf("%.2f ", data1.floatArray[i]);

    printf("\n");
    printf("Char array: ");
    for(i = 0; i < CHAR_ARRAY_SIZE; ++i)
        printf("%c ", data2.charArray[i]);

    printf("\n");
    printf("String array: ");
    for(i = 0; i < NUM_STRINGS; ++i)
        printf("%s ", data2.strArray[i]);

    printf("\n");

    printf("\n");
    return 0;
}