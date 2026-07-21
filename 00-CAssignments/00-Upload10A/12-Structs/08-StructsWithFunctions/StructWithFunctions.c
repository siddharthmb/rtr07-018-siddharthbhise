#include <stdio.h>

struct MyData
{
    int    i;
    float  f;
    double d;
};

typedef struct MyData MyData;

int main(void)
{
    // functions
    MyData addMembers(MyData data[], int size);
    void display(MyData);

    // variables
    MyData data[3], answerData;
    int i;

    // code
    printf("\n\n");
    for(i = 0; i < 3; ++i)
    {
        printf("***** ELEMENT %d *****\n", i + 1);
        printf("Enter i: ");
        scanf("%d", &data[i].i);
        printf("Enter f: ");
        scanf("%f", &data[i].f);
        printf("Enter d: ");
        scanf("%lf", &data[i].d);

        // display(data[i]);
    }

    answerData = addMembers(data, 3);
    printf("\n\n");

    printf("answer.i = %d\n",  answerData.i);
    printf("answer.f = %f\n",  answerData.f);
    printf("answer.d = %lf\n", answerData.d);

    printf("\n");
    return 0;
}

MyData addMembers(MyData data[], int size)
{
    int i;
    MyData answerData = {0};

    for(i = 0; i < size; ++i)
    {
        answerData.i = answerData.i + data[i].i;
        answerData.f = answerData.f + data[i].f;
        answerData.d = answerData.d + data[i].d;
    }

    return answerData;
}

void display(MyData data)
{
    printf("display(): data.i = %d\n", data.i);
    printf("display(): data.f = %f\n", data.f);
    printf("display(): data.d = %lf\n", data.d);
}
