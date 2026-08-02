#include <stdio.h>
#include <stdarg.h>

int main(void)
{
    // functions
    void AddNumbers(int, ...);

    // code
    printf("\n\n");
    AddNumbers(5, 3, 3, 3, 3, 3);

    printf("\n");
    return 0;
}

void AddNumbers(int totalNums, ...)
{
    // functions
    int _AddNumbers(int, va_list);

    // variables
    int sum;
    va_list listOfNumbers;

    va_start(listOfNumbers, totalNums);

    sum = _AddNumbers(totalNums, listOfNumbers);
    printf("The sum of all the numbers is %d\n", sum);

    va_end(listOfNumbers);
}

int _AddNumbers(int totalElements, va_list list)
{
    int sum = 0;
    int n;

    // code
    while(totalElements--)
    {
        n = va_arg(list, int);
        sum = sum + n;
    }

    return sum;
}
