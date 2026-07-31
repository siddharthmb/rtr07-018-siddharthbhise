#include <stdio.h>
#include <stdlib.h>

struct Data
{
    int *p_int;
    int i;

    float *p_float;
    float f;

    double *p_double;
    double d;
};

typedef struct Data Data;

int main(void)
{
    // variables
    Data *p_data = NULL;

    // code
    printf("\n\n");
    p_data = (Data *)malloc(sizeof(Data));
    if(p_data == NULL)
    {
        printf("Failed to allocate %zu bytes\n", sizeof(Data));
        exit(1);
    }

    p_data->i = 123;
    p_data->p_int = &(p_data->i);
    p_data->f = 12.3f;
    p_data->p_float = &(p_data->f);
    p_data->d = 1.23;
    p_data->p_double = &(p_data->d);

    printf("\n\n");
    printf("p_data->i = %d \t    p_data->p_int    = %p\n", p_data->i, p_data->p_int);
    printf("p_data->f = %.1f \t  p_data->p_float  = %p\n", p_data->f, p_data->p_float);
    printf("p_data->d = %.3lf \t p_data->p_double = %p\n", p_data->d, p_data->p_double);

    if(p_data)
    {
        free(p_data);
        p_data = NULL;
        printf("Freed memory allocated to p_data\n");
    }

    printf("\n");
    return 0;
}