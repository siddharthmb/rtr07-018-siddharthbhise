#include <stdio.h>

int globalCount = 0;

int main(void)
{
    // functions
    void changeCount(void);
    void changeCountOne(void);
    void changeCountTwo(void);

    // code
    printf("\n\n");

    changeCount();
    changeCountOne();
    changeCountTwo();

    printf("\n");
    return 0;
}

void changeCount(void)
{
    // code
    ++globalCount;
    printf("changeCount(): globalCount = %d\n", globalCount);
}
