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

    printf("sizeof(int) = %zu bytes, sizeof(int *) = %zu bytes\n", sizeof(int), sizeof(int *));
    printf("sizeof(char) = %zu bytes, sizeof(char *) = %zu bytes\n", sizeof(char), sizeof(char *));
    printf("sizeof(float) = %zu bytes, sizeof(float *) = %zu bytes\n", sizeof(float), sizeof(float *));
    printf("sizeof(double) = %zu bytes, sizeof(double *) = %zu bytes\n", sizeof(double), sizeof(double *));
    printf("sizeof(Employee) = %zu bytes, sizeof(Employee *) = %zu bytes\n", sizeof(Employee), sizeof(Employee *));

    printf("\n");
    return 0;
}