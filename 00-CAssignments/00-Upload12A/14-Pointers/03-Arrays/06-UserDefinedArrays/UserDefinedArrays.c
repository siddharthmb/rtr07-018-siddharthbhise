#include <stdio.h>
#include <stdlib.h>

#define INTSIZE     sizeof(int)
#define FLOATSIZE   sizeof(float)
#define DOUBLESIZE  sizeof(double)
#define CHARSIZE    sizeof(char)

int main(void)
{
    // functions
    unsigned int acceptNFromUserWithLog(const char *);

    // variables
    int *p_intArray = NULL;
    unsigned int nIntegers;

    float *p_floatArray = NULL;
    unsigned int nFloats;

    double *p_doubleArray = NULL;
    unsigned int nDoubles;

    char *p_charArray = NULL;
    unsigned int nCharacters;

    int i;

    // code
    printf("\n\n");
    nIntegers   = acceptNFromUserWithLog("Enter number of integers to store in int array: ");
    p_intArray = (int *)malloc(INTSIZE * nIntegers);
    if(p_intArray == NULL)
    {
        printf("Memory allocation failed for %zu bytes failed for int array!!!", INTSIZE * nIntegers);
        exit(1);
    }
    for(i = 0; i < nIntegers; ++i)
    {
        *(p_intArray + i) = i * 10;
        printf("*(p_intArray + %d) = %d \t (p_intArray + %d) = %p\n", i, *(p_intArray + i), i, (p_intArray + i));
    }
    printf("\n\n");


    nFloats     = acceptNFromUserWithLog("Enter number of floats to store in float array: ");
    p_floatArray = (float *)malloc(FLOATSIZE * nFloats);
    if(p_floatArray == NULL)
    {
        printf("Memory allocation failed for %zu bytes while doing float array through pointer\n", FLOATSIZE * nFloats);
        exit(1);
    }
    for(i = 0; i < nFloats; ++i)
    {
        *(p_floatArray + i) = i * 3.14f;
        printf("*(p_floatArray + %d) = %.3f \t (p_floatArray + %d) = %p\n", i, *(p_floatArray + i), i, (p_floatArray + i));
    }
    printf("\n\n");


    nDoubles    = acceptNFromUserWithLog("Enter number of doubles to store in double array: ");
    p_doubleArray = (double *)malloc(DOUBLESIZE * nDoubles);
    if(p_doubleArray == NULL)
    {
        printf("Malloc failed for %zu bytes for double array through pointer\n", DOUBLESIZE * nDoubles);
        exit(1);
    }
    for(i = 0; i < nDoubles; ++i)
    {
        *(p_doubleArray + i) = i * 1.33;
        printf("*(p_doubleArray + %d) = %.3lf \t (p_doubleArray + %d) = %p\n", i, p_doubleArray[i], i, &p_doubleArray[i]);
    }
    printf("\n\n");


    nCharacters = acceptNFromUserWithLog("Enter number of characters to store in char array: ");
    p_charArray = (char *)malloc(CHARSIZE * nCharacters);
    if(p_charArray == NULL)
    {
        printf("Memory allocation for %zu bytes failed!\n", CHARSIZE * nCharacters);
        exit(1);
    }
    for(i = 0; i < nCharacters; ++i)
    {
        *(p_charArray + i) = 65 + i;
        printf("*(p_charArray + %d) = %c \t (p_charArray + %d) = %p\n", i, *(p_charArray + i), i, &p_charArray[i]);
    }
    printf("\n\n");


    printf("Freeing p_intArray...\n");
    free(p_intArray); 
    p_intArray = NULL;

    printf("Freeing p_floatArray...\n");
    free(p_floatArray); 
    p_floatArray = NULL;
    
    printf("Freeing p_doubleArray...\n");
    free(p_doubleArray); 
    p_doubleArray = NULL;

    printf("Freeing p_charArray...\n");
    free(p_charArray); 
    p_charArray = NULL;

    printf("\n");
    return 0;
}

unsigned int acceptNFromUserWithLog(const char *str)
{
    // variables
    unsigned int n;

    // code
    printf(str);
    scanf("%u", &n);

    return n;
}
