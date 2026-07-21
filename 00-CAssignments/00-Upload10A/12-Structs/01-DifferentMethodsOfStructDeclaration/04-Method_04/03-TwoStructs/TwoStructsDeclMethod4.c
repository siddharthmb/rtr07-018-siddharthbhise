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

int main(void)
{
    // variables
    MyPoint point;
    MyPointProperties pointProperties;

    // code
    printf("\n\n");
    printf("Enter the x coordinate: ");
    scanf("%d", &point.x);
    printf("Enter the y coordinate: ");
    scanf("%d", &point.y);

    if(point.x == 0 && point.y == 0)
    {
        printf("Point lies at the origin!\n");
    }
    else
    {
        if(point.x == 0)
        {
            if(point.y < 0)
                strcpy(pointProperties.axisLocation, "Negative Y");
            else
                strcpy(pointProperties.axisLocation, "Positive Y");

            printf("Point lies on the Y axis with %s\n", pointProperties.axisLocation);
        }
        else if(point.y == 0)
        {
            if(point.x < 0)
                strcpy(pointProperties.axisLocation, "Negative X");
            else
                strcpy(pointProperties.axisLocation, "Positive X");

            printf("Point lies on the X axis with %s\n", pointProperties.axisLocation);
        }
        else
        {
            pointProperties.axisLocation[0] = '\0';
            if(point.x > 0 && point.y > 0)
                pointProperties.quadrant = 1;
            else if(point.x < 0 && point.y > 0)
                pointProperties.quadrant = 2;
            else if(point.x < 0 && point.y < 0)
                pointProperties.quadrant = 3;
            else
                pointProperties.quadrant = 4;

            printf("Point lies in the quadrant %d\n", pointProperties.quadrant);
        }
    }

    printf("\n");
    return 0;
}