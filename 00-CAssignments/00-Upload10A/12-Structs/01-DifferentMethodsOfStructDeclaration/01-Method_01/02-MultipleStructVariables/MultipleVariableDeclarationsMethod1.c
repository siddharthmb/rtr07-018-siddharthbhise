#include <stdio.h>

struct MyPoint
{
    int x;
    int y;
};

typedef struct MyPoint MyPoint;

MyPoint pointA, pointB, pointC, pointD, pointE;

int main(void)
{
    // code
    printf("\n\n");
    pointA.x = 1,  pointA.y = 1;
    pointB.x = 10, pointB.y = 15;
    pointC.x = -1, pointC.y = -1;
    pointD.x = 21, pointD.y = 61;
    pointE.x = 5,  pointE.y = 5;

    printf("Coordinates (x, y) of Point 'A' are: (%d, %d)\n", pointA.x, pointA.y);
    printf("Coordinates (x, y) of Point 'B' are: (%d, %d)\n", pointB.x, pointB.y);
    printf("Coordinates (x, y) of Point 'C' are: (%d, %d)\n", pointC.x, pointC.y);
    printf("Coordinates (x, y) of Point 'D' are: (%d, %d)\n", pointD.x, pointD.y);
    printf("Coordinates (x, y) of Point 'E' are: (%d, %d)\n", pointE.x, pointE.y);

    printf("\n");
    return 0;
}