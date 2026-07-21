#include <stdio.h>

struct MyPoint
{
    int x, y;
};

struct MyPointProperties
{
    int quadrant;
    char axisLocation[10];
};

typedef struct MyPoint MyPoint;
typedef struct MyPointProperties MyPointProperties;

MyPoint point;
MyPointProperties pointProperties;

int main(void)
{
    // code
    printf("\n\n");
    printf("Enter x for point: ");
    scanf("%d", &point.x);
    printf("Enter y for point: ");
    scanf("%d", &point.y);

    printf("\n\n");
    printf("Point coordinates (x, y) are (%d, %d)\n", point.x, point.y);

    if(point.x == 0 && point.y == 0)
    {
        printf("The point lies at the origin!\n");
    }
    else
    {
        if(point.x == 0)
        {
            if(point.y < 0)
                strcpy(pointProperties.axisLocation, "Negative Y");
            else
                strcpy(pointProperties.axisLocation, "Positive Y");

            printf("Point lies on the X axis, with %s\n", pointProperties.axisLocation);
        }
        else if(point.y == 0)
        {
            if(point.x < 0)
                strcpy(pointProperties.axisLocation, "Negative X");
            else
                strcpy(pointProperties.axisLocation, "Positive X");

            printf("Point lies on the Y axis, with %s\n", pointProperties.axisLocation);
        }
        else
        {
            pointProperties.axisLocation[0] = '\0';
            // both x and y are non-zero
            if(point.x > 0 && point.y > 0)
                pointProperties.quadrant = 1;
            else if(point.x < 0 && point.y > 0)
                pointProperties.quadrant = 2;
            else if(point.x < 0 && point.y < 0)
                pointProperties.quadrant = 3;
            else
                pointProperties.quadrant = 4;

            printf("Point lies in the %d quadrant\n", pointProperties.quadrant);
        }
    }

    printf("\n");
    return 0;
}