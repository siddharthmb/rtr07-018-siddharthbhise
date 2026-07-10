#include <stdio.h>

int main(void)
{
    // function declarations
    void changeCount(void);

    // variable declaration
    extern int globalCount;

    // code
    printf("\n\n");
    printf("Value of globalCount before changeCount() is %d\n", globalCount);
    changeCount();
    printf("Value of globalCount after changeCount() is %d\n", globalCount);

    printf("\n");

    return 0;
}

int globalCount = 0;

void changeCount(void)
{
    globalCount = 55;
    printf("changeCount(): value of globalCount here is %d\n", globalCount);
}
