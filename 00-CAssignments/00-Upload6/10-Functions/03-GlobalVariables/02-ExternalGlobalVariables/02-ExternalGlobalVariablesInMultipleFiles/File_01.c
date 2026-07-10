#include <stdio.h>

extern int globalCount;

void changeCountOne(void)
{
    // code
    ++globalCount;
    printf("changeCountOne(): globalCount = %d\n", globalCount);
}