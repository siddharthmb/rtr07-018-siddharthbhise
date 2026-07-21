#include <stdio.h>

struct MyPoint
{
    int x, y;
};

typedef struct MyPoint MyPoint;

int main(void)
{
    // variables
    MyPoint point1, point2;

    // code
    printf("\n\n");
    printf("Enter X-coordinate for point 1: ");
    scanf("%d", &point1.x);
    printf("Enter Y-coordinate for point 1: ");
    scanf("%d", &point1.y);

    printf("Enter X-coordinate for point 2: ");
    scanf("%d", &point2.x);
    printf("Enter Y-coordinate for point 2: ");
    scanf("%d", &point2.y);

    printf("You entered below points\n");
    printf("Point 1 (x, y) : (%d, %d)\n", point1.x, point1.y);
    printf("Point 2 (x, y) : (%d, %d)\n", point2.x, point2.y);

    printf("\n");
    return 0;
}