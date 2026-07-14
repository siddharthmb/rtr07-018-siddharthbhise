#include <stdio.h>

#define MAX_LEN 512

int main(void)
{
    // functions
    int smbstrlen(char[]);

    // variables
    char array[5][10] = {"Hello", "World", "Siddharth", "Fatema", "RTR7"};
    int charSize;
    int arraySize, numElements, numRows, numCols;
    int actualNumChars = 0, i;

    // code
    printf("\n\n");
    charSize = sizeof(char);
    arraySize = sizeof(array);
    numRows = arraySize / sizeof(array[0]);
    numCols = sizeof(array[0]) / charSize;
    numElements = numRows * numCols;
    printf("Array size: %d\trows: %d\tcols: %d\telements: %d\t", arraySize, numRows, numCols, numElements);

    for(i = 0; i < numRows; ++i)
    {
        actualNumChars = actualNumChars + smbstrlen(array[i]);
    }

    printf("Actual number of elements in the 2D character (string) array is : %d\t", actualNumChars);
    printf("\n\n");
    printf("Strings in the 2D array are: \n");
    printf("%s ", array[0]);
    printf("%s ", array[1]);
    printf("%s ", array[2]);
    printf("%s ", array[3]);
    printf("%s ", array[4]);

    return 0;
}

int smbstrlen(char s[])
{
    // variables
    int i = 0;
    while(s[i] != '\0') ++i;

    return i;
}
