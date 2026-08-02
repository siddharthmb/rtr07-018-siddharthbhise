#include <stdio.h>
#include <stdarg.h>

#define NUM_TO_FIND  5
#define NUM_ELEMENTS 5

int main(void)
{
    // functions
    void FindNum(int, int, ...);

    // code
    printf("\n\n");

    FindNum(NUM_TO_FIND, NUM_ELEMENTS, 5, 5, 5, 5, 5);

    printf("\n");
    return 0;
}

void FindNum(int numToFind, int totalElements, ...)
{
    // functions
    int vaFindNum(int, int, va_list);

    // code
    int count;
    va_list listOfNumbers;

    // code
    va_start(listOfNumbers, totalElements);

    count = vaFindNum(numToFind, totalElements, listOfNumbers);
    printf("%d occurs %d time(s) in total of %d elements!\n", numToFind, count, totalElements);

    va_end(listOfNumbers);
}

int vaFindNum(int numToFind, int totalElements, va_list list)
{
    int counter = 0;
    int n;

    while(totalElements)
    {
        n = va_arg(list, int);
        if(n == numToFind) counter++;
        --totalElements;
    }

    return counter;
}
