#include <stdio.h>

struct MyNumber
{
    int num, numtable[12];
};

typedef struct MyNumber MyNumber;

struct NumTables
{
    MyNumber a, b, c;
};

typedef struct NumTables NumTables;

int main(void)
{
    // variables
    NumTables tables;
    int i;

    // code
    printf("\n\n");
    tables.a.num = 2;
    for(i = 0; i < 12; ++i)
        tables.a.numtable[i] = tables.a.num * (i + 1);

    tables.b.num = 3;
    for(i = 0; i < 12; ++i)
        tables.b.numtable[i] = tables.b.num * (i + 1);

    tables.c.num = 4;
    for(i = 0; i < 12; ++i)
        tables.c.numtable[i] = tables.c.num * (i + 1);

    for(i = 0; i < 12; ++i)
    {
        printf("%2d\t%2d\t%2d\n", tables.a.numtable[i], tables.b.numtable[i], tables.c.numtable[i]);
    }

    printf("\n");
    return 0;
}