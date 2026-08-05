#include <stdio.h>

struct Number
{
    int number;
    int numberTable[10];
};

typedef struct Number Number;

struct NumberTable
{
    Number n;
};

typedef struct NumberTable NumberTable;

int main(void)
{
    // variables
    NumberTable tables[10];
    int i, j;

    // code
    printf("\n\n");
    for(i = 0; i < 10; ++i)
    {
        tables[i].n.number = (i + 1);
        printf("Table of %2d:", tables[i].n.number);
        for(j = 0; j < 10; ++j)
        {
            tables[i].n.numberTable[j] = tables[i].n.number * (j + 1);
            printf(" %2d", tables[i].n.numberTable[j]);
        }

        printf("\n");
    }

    printf("\n");
    return 0;
}