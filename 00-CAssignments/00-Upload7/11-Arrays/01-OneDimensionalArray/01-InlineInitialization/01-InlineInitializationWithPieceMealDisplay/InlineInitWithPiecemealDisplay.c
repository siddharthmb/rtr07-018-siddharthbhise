#include <stdio.h>

int main(void)
{
    int arrayOfInts[] = {1, 4, 9, 16, 25, 26};
    int intSize, arraySize, arrayTotalElements;

    float arrayOfFloats[] = {1.2f, 3.14f, 59.0f, 987.234f, 87.54f};
    int floatSize, fArraySize, fArrayTotalElements;

    char arrayOfChars[] = {'A', 'S', 'T', 'R', 'O', 'M', 'E', 'D' ,'I' ,'C' ,'O' ,'M' ,'P'};
    int charSize, cArraySize, cArrayTotalElements;

    // code
    printf("\n\n");
    printf("In-line initialization and piecemeal display of elemtns of the integer array: \n");
    printf("arrayOfInts[0] = %d\n", arrayOfInts[0]);
    printf("arrayOfInts[1] = %d\n", arrayOfInts[1]);
    printf("arrayOfInts[2] = %d\n", arrayOfInts[2]);
    printf("arrayOfInts[3] = %d\n", arrayOfInts[3]);
    printf("arrayOfInts[4] = %d\n", arrayOfInts[4]);
    printf("arrayOfInts[5] = %d\n", arrayOfInts[5]);

    intSize = sizeof(int);
    arraySize = sizeof(arrayOfInts);
    arrayTotalElements = arraySize / intSize;
    printf("Size of datatype 'int'        : %u\n", intSize);
    printf("Total elements in arrayOfInts : %u\n", arrayTotalElements);
    printf("Size of arrayOfInts           : %u\n", arraySize);

    printf("\n\n");

    printf("In-line initialization and piecemeal display of elemtns of the float array: \n");
    printf("arrayOfFloats[0] = %f\n", arrayOfFloats[0]);
    printf("arrayOfFloats[1] = %f\n", arrayOfFloats[1]);
    printf("arrayOfFloats[2] = %f\n", arrayOfFloats[2]);
    printf("arrayOfFloats[3] = %f\n", arrayOfFloats[3]);
    printf("arrayOfFloats[4] = %f\n", arrayOfFloats[4]);

    floatSize = sizeof(float);
    fArraySize = sizeof(arrayOfFloats);
    fArrayTotalElements = fArraySize / floatSize;
    printf("Size of datatype 'float'        : %u\n", floatSize);
    printf("Total elements in arrayOfFloats : %u\n", fArrayTotalElements);
    printf("Size of arrayOfFloats           : %u\n", fArraySize);

    printf("\n\n");

    printf("In-line initialization and piecemeal display of elemtns of the char array: \n");
    printf("arrayOfChars[0]  = %c\n", arrayOfChars[0]);
    printf("arrayOfChars[1]  = %c\n", arrayOfChars[1]);
    printf("arrayOfChars[2]  = %c\n", arrayOfChars[2]);
    printf("arrayOfChars[3]  = %c\n", arrayOfChars[3]);
    printf("arrayOfChars[4]  = %c\n", arrayOfChars[4]);
    printf("arrayOfChars[5]  = %c\n", arrayOfChars[5]);
    printf("arrayOfChars[6]  = %c\n", arrayOfChars[6]);
    printf("arrayOfChars[7]  = %c\n", arrayOfChars[7]);
    printf("arrayOfChars[8]  = %c\n", arrayOfChars[8]);
    printf("arrayOfChars[9]  = %c\n", arrayOfChars[9]);
    printf("arrayOfChars[10] = %c\n", arrayOfChars[10]);
    printf("arrayOfChars[11] = %c\n", arrayOfChars[11]);
    printf("arrayOfChars[12] = %c\n", arrayOfChars[12]);

    charSize = sizeof(char);
    cArraySize = sizeof(arrayOfChars);
    cArrayTotalElements = cArraySize / charSize;
    printf("Size of datatype 'char'        : %u\n", charSize);
    printf("Total elements in arrayOfChars : %u\n", cArrayTotalElements);
    printf("Size of arrayOfChars           : %u\n", cArraySize);

    printf("\n");

    return 0;
}
