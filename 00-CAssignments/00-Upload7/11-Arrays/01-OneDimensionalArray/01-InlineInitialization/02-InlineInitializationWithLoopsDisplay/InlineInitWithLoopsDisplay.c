#include <stdio.h>

int main(void)
{
    // variables and arrays
    int arrayOfInts[] = {10, 20, 30, 50, 40, 90};
    int intSize, arrayOfIntsSize, arrayOfIntsTotalElements;

    float arrayOfFloats[] = {3.14f, 6.28f, 31.4f, 32.8f, 50.0f, 60.0f};
    int floatSize, arrayOfFloatsSize, arrayOfFloatsTotalElements;

    char arrayOfChars[] = {'A', 'S', 'T', 'R', 'O', 'M', 'E', 'D', 'I', 'C', 'O', 'M', 'P'};
    int charSize, arrayOfCharsSize, arrayOfCharsTotalElements;

    int i;

    // code
    printf("In-line initialization and loop for display, the elements of character array: \n");
    charSize = sizeof(char);
    arrayOfCharsSize = sizeof(arrayOfChars);
    arrayOfCharsTotalElements = arrayOfCharsSize / charSize;
    for(i = 0; i < arrayOfCharsTotalElements; ++i)
    {
        printf("arrayOfChars[%d] ( Elements %d)        : %c\n", i, i + 1, arrayOfChars[i]);
    }

    printf("\n");
    printf("Size of datatype 'char'        : %u\n", charSize);
    printf("Total elements in arrayOfChars : %u\n", arrayOfCharsTotalElements);
    printf("Size of arrayOfChars           : %u\n", arrayOfCharsSize);

    printf("\n\n");

    printf("In-line initialization and loop for display, the elements of floats array: \n");
    floatSize = sizeof(float);
    arrayOfFloatsSize = sizeof(arrayOfFloats);
    arrayOfFloatsTotalElements = arrayOfFloatsSize / floatSize;
    i = 0;
    while(i < arrayOfFloatsTotalElements)
    {
        printf("arrayOfFloats[%d] ( Elements %d)        : %f\n", i, i + 1, arrayOfFloats[i]);
        ++i;
    }

    printf("\n");
    printf("Size of datatype 'float'        : %u\n", floatSize);
    printf("Total elements in arrayOfFloats : %u\n", arrayOfFloatsTotalElements);
    printf("Size of arrayOfFloats           : %u\n", arrayOfFloatsSize);

    printf("\n\n");

    printf("In-line initialization and loop for display, the elements of integer array: \n");
    intSize = sizeof(int);
    arrayOfIntsSize = sizeof(arrayOfInts);
    arrayOfIntsTotalElements = arrayOfIntsSize / intSize;
    i = 0;
    do
    {
        printf("arrayOfInts[%d] ( Elements %d)        : %d\n", i, i + 1, arrayOfInts[i]);
        ++i;

    } while(i < arrayOfIntsTotalElements);

    printf("\n");
    printf("Size of datatype 'int'        : %u\n", intSize);
    printf("Total elements in arrayOfInts : %u\n", arrayOfIntsTotalElements);
    printf("Size of arrayOfInts           : %u\n", arrayOfIntsSize);

    printf("\n\n");
    return 0;
}