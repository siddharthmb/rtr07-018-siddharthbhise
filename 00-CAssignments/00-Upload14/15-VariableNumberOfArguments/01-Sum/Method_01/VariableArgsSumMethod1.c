#include <stdio.h>
#include <stdarg.h>

int main(void)
{
    // functions
    int additionOfVariableArguments(int, ...);

    // variables
    int ans;

    // code
    printf("\n\n");
    ans = additionOfVariableArguments(5, 25, 25, 30, 30, 50);
    printf("ans = %d\n", ans);

    ans = additionOfVariableArguments(10, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100);
    printf("ans = %d\n", ans);

    printf("\n");
    return 0;
}

int additionOfVariableArguments(int totalArgs, ...)
{
    // variables
    int sum = 0;
    int num;
    va_list listOfNumbers;

    // code
    va_start(listOfNumbers, totalArgs);
    while(totalArgs)
    {
        num = va_arg(listOfNumbers, int);
        sum = sum + num;
        --totalArgs;
    }

    va_end(listOfNumbers);

    return sum;
}
