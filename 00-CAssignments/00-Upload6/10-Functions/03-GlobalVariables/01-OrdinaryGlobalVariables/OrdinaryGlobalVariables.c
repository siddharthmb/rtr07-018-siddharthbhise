#include <stdio.h>

int globalCount = 0;
int main(void)
{
    // function declarations
    void changeCountOne(void);
    void changeCountTwo(void);
    void changeCountThree(void);

    // code
    printf("\n\n");
    printf("main(): Value of globalCount variable is %d\n", globalCount);

    changeCountOne();
    changeCountTwo();
    changeCountThree();

    printf("\n");

    return 0;
}

void changeCountOne(void)
{
    // code
    globalCount = 100;
    printf("changCountOne(): value of globalCount variable is %d\n", globalCount);
}

void changeCountTwo(void)
{
    // code
    globalCount = globalCount + 50;
    printf("changeCountTwo(): value of globalCount variable is %d\n", globalCount);
}

void changeCountThree(void)
{
    // code
    globalCount = globalCount + 50;
    printf("changeCountThree(): value of globalCount variable is %d\n", globalCount);
}
