#include <stdio.h>

struct MyPoint
{
    int x, y;
} pointA, pointB, pointC, pointD, pointE;

int main(void)
{
    // code
    printf("\n\n");
    pointA.x = 4,  pointA.y = 7;
    pointA.x = 25, pointB.y = 64;
    pointC.x = 9,  pointC.y = 1;
    pointD.x = 44, pointD.y = 71;
    pointE.x = 14, pointE.y = 27;

    printf("Coordinates (x, y) of point A are: (%d, %d)\n", pointA.x, pointA.y);
    printf("Coordinates (x, y) of point B are: (%d, %d)\n", pointB.x, pointB.y);
    printf("Coordinates (x, y) of point C are: (%d, %d)\n", pointC.x, pointC.y);
    printf("Coordinates (x, y) of point D are: (%d, %d)\n", pointD.x, pointD.y);
    printf("Coordinates (x, y) of point E are: (%d, %d)\n", pointE.x, pointE.y);

    printf("\n");
    return 0;
}