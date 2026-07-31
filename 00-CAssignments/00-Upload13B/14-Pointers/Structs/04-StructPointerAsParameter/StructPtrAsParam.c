#include <stdio.h>
#include <stdlib.h>

struct Data
{
    int i;
    float f;
    double d;
};

typedef struct Data Data;

int main(void)
{
    // functions
    void ChangeValues(Data *);

    // variables
    Data *p_data = NULL;

    // code
    printf("\n\n");
    p_data = (Data *)malloc(sizeof(Data));
    if(p_data == NULL)
    {
        printf("Failed to allocate %zu bytes for Data variable\n", sizeof(Data));
        exit(1);
    }

    p_data->i = 6344;
    p_data->f = 4.121f;
    p_data->d = 3.14;

    printf("***** BEFORE ChangeValues is called on p_data\n");
    printf("p_data->i = %d\n", p_data->i);
    printf("p_data->f = %.2f\n", p_data->f);
    printf("p_data->d = %.2lf\n", p_data->d);

    printf("\n\n");
    ChangeValues(p_data);

    printf("***** AFTER ChangeValues is called on p_data\n");
    printf("p_data->i = %d\n", p_data->i);
    printf("p_data->f = %.2f\n", p_data->f);
    printf("p_data->d = %.2lf\n", p_data->d);

    printf("\n");
    return 0;
}

void ChangeValues(Data *pData)
{
    pData->i = pData->i * 2;
    pData->f = pData->f * 2.0f;
    pData->d = pData->d * 2.0;
}
