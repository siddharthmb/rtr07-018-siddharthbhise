#include <stdio.h>

extern int globalCount;

void changeCountTwo(void)
{
    // code
    ++globalCount;
    printf("changeCountTwo(): globalCount = %d\n");
}
