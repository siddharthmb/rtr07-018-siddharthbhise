#include <stdio.h>

int main(void)
{
    // defining the struct
    struct MyPoint
    {
        int x, y;
    };

    typedef struct MyPoint MyPoint;

    // variables
    MyPoint point1, point2, point3;

    // code
    printf("\n\n");

    point1.x = 2, point1.y = 8;
    point2.x = 5, point2.y = 6;
    point3.x = 3, point3.y = 3;

    printf("Coordinates Point 1 (x, y) : (%d, %d)\n", point1.x, point1.y);
    printf("Coordinates Point 2 (x, y) : (%d, %d)\n", point2.x, point2.y);
    printf("Coordinates Point 3 (x, y) : (%d, %d)\n", point3.x, point3.y);

    printf("\n");
    return 0;
}