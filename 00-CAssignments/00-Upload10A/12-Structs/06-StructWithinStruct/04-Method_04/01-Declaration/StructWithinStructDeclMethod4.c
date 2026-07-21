#include <stdio.h>

int main(void)
{
    // variables
    int length, breadth, area;

    struct Point
    {
        int x, y;
    };
    typedef struct Point Point;

    struct Rectangle
    {
        Point point1, point2;
    };
    typedef struct Rectangle Rectangle;

    Rectangle rect;

    // code
    printf("\n\n");
    printf("Enter the leftmost x-coordinate: ");
    scanf("%d", &rect.point1.x);
    printf("Enter the bottommost y-coordinate: ");
    scanf("%d", &rect.point1.y);
    printf("Enter the rightmost x-coordinate: ");
    scanf("%d", &rect.point2.x);
    printf("Enter the topmost y-coordinate: ");
    scanf("%d", &rect.point2.y);

    length = rect.point2.y - rect.point1.y;
    breadth = rect.point2.x - rect.point1.x;

    if(length < 0) length = length * -1;
    if(breadth < 0) breadth = breadth * -1;

    area = length * breadth;

    printf("Length of the rectangle = %d\n", length);
    printf("Breadth of the rectangle = %d\n", breadth);
    printf("Area of the rectangle = %d\n", area);

    printf("\n");
    return 0;
}