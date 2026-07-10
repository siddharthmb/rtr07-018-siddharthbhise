#include <stdio.h>

int main(void)
{
    // functions
    void changeCount(void);

    // variables
    int a = 90;

    // code
    printf("\n\n");
    printf("value of 'a' = %d\n", a);

    changeCount();
    changeCount();

    printf("\n");
    return 0;
}

void changeCount(void)
{
    static int localNum = 55;
    printf("changeCount(): localNum = %d\n", localNum++);
}
