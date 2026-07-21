#include <stdio.h>

struct MyPoint
{
    int x, y;
};

typedef struct MyPoint MyPoint;

int main(void)
{
    // vars
    MyPoint point1, point2, point3;

    // code
    printf("\n\n");
    point1.x = 23, point1.y = 45;
    point2.x = 3,  point2.y = 5;
    point3.x = 2,  point3.y = 4;

    printf("Point 1 (x, y): (%d, %d)\n", point1.x, point1.y);
    printf("Point 2 (x, y): (%d, %d)\n", point2.x, point2.y);
    printf("Point 3 (x, y): (%d, %d)\n", point3.x, point3.y);

    printf("\n");
    return 0;
}