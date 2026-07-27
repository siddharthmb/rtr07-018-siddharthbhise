#include <stdio.h>

struct Employee
{
    char name[100];
    int age;
    float salary;
    char sex;
    char marital_status;
};

typedef struct Employee Employee;

int main(void)
{
    // code
    printf("\n\n");
    printf("sizeof(int) = %zu \t sizeof(int *) = %zu \t sizeof(int **)\n", sizeof(int), sizeof(int *), sizeof(int **));
    printf("sizeof(float) = %zu \t sizeof(float *) = %zu \t sizeof(float **)\n", sizeof(float), sizeof(float *), sizeof(float **));
    printf("sizeof(double) = %zu \t sizeof(double *) = %zu \t sizeof(double **)\n", sizeof(double), sizeof(double *), sizeof(double **));
    printf("sizeof(char) = %zu \t sizeof(char *) = %zu \t sizeof(char **)\n", sizeof(char), sizeof(char *), sizeof(char **));
    printf("sizeof(Employee) = %zu \t sizeof(Employee *) = %zu \t sizeof(Employee **)\n", sizeof(Employee), sizeof(Employee *), sizeof(Employee **));

    printf("\n");
    return 0;
}