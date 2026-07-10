#include <stdio.h>

int main(void)
{
    // variable declarations
    int a = 10;

    // functions
    void changeCount(void);

    // code
    printf("\n\n");
    printf("value of 'a' is %d\n", a);

    changeCount();
    changeCount();

    return 0;
}

void changeCount(void)
{
    // variables
    int localNum = 33;
    
    // code
    localNum = localNum + 1;
    printf("changeCount(): localNum = %d\n", localNum);
}