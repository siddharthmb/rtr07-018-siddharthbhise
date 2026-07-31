#include <stdio.h>

int main(void)
{
    // functions
    int additionOfIntegers(int, int);
    int subtractionOfIntegers(int, int);
    float additionOfFloats(float, float);

    // variables
    typedef int (*IntegerMathFnPtr)(int, int);
    typedef float (*FloatMathFnPtr)(float, float);
    IntegerMathFnPtr intMathFnPtr = NULL;
    FloatMathFnPtr floatMathFnPtr = NULL;

    int intAnswer = 0;
    float floatAnswer = 0.0f;

    // code
    printf("\n\n");
    intMathFnPtr = additionOfIntegers;
    intAnswer = intMathFnPtr(500, 50);
    printf("Addition of 500 & 50 done using function pointer to additionOfIntegers(int, int), yielded: %d\n", intAnswer);

    intMathFnPtr = subtractionOfIntegers;
    intAnswer = intMathFnPtr(500, 50);
    printf("Subtraction of 500 & 50 done using function pointer to subtractionOfIntegers(int, int), yielded: %d\n", intAnswer);

    floatMathFnPtr = additionOfFloats;
    floatAnswer = floatMathFnPtr(500.0f, 70.0f);
    printf("Addition of 500.0f & 70.0f done using function pointer to additionOfFloats(float, float), yielded: %f\n", floatAnswer);

    printf("\n");
    return 0;
}

int additionOfIntegers(int a, int b)
{
    // code
    return a + b;
}

int subtractionOfIntegers(int a, int b)
{
    // code
    return a - b;
}

float additionOfFloats(float a, float b)
{
    // code
    return a + b;
}
