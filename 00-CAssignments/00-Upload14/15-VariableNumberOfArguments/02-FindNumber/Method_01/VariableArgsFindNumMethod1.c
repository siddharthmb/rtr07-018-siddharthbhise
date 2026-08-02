#include <stdio.h>
#include <stdarg.h>

#define NUM_TO_FIND   4
#define TOTAL_NUMBERS 5

int main(void)
{
    // functions
    void SearchNum(int, int, ...);

    // code
    printf("\n\n");
    SearchNum(NUM_TO_FIND, TOTAL_NUMBERS, 65, 454, 4, 665, 2);

    printf("\n");
    return 0;
}

void SearchNum(int numToFind, int totalEle, ...)
{
    // variables
    int _totalEle = totalEle;
    int counter = 0;
    int n;
    va_list listOfNumbers;

    // code
    va_start(listOfNumbers, totalEle);
    while(totalEle)
    {
        n = va_arg(listOfNumbers, int);
        if(n == numToFind) counter++;

        --totalEle;
    }

    va_end(listOfNumbers);

    printf("In %d elements, %d occurs %d time(s)!\n", _totalEle, numToFind, counter);
}