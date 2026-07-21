#include <stdio.h>

int main(void)
{
    // variables
    int length, breadth, area;

    struct Rectangle
    {
        struct Point
        {
            int x, y;
        } point1, point2;
    } rect = {{14, 85}, {35, 156}};

    // code
    printf("\n\n");
    length = rect.point2.y - rect.point1.y;
    breadth = rect.point2.x - rect.point1.x;

    if(length < 0) length = length * -1;
    if(breadth < 0) breadth = breadth * -1;

    area = length * breadth;

    printf("Length of the rectangle: %d\n", length);
    printf("Breadth of the rectangle: %d\n", breadth);
    printf("Area of the rectangle: %d\n", area);

    printf("\n");
    return 0;
}