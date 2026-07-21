#include <stdio.h>

struct Employee
{
    char name[100];
    unsigned int age;
    char gender;
    double salary;
};

typedef struct Employee Employee;

struct MyData
{
    int    i;
    float  f;
    double d;
    char   c;
};

typedef struct MyData MyData;

int main(void)
{
    Employee e = {"Sourabh", 34, 'M', 500000.89};
    MyData data = {23, 45.32f, 45.232, 'A'};

    // code
    printf("\n\n");

    printf("Employee details\n");
    printf("Name   : %s\n",  e.name);
    printf("Age    : %d\n",  e.age);
    printf("Gender : %c\n",  e.gender);
    printf("Salary : %lf\n", e.salary);

    printf("\n\n");
    printf("Data details\n");
    printf("data.i = %d\n",  data.i);
    printf("data.f = %f\n",  data.f);
    printf("data.d = %lf\n", data.d);
    printf("data.c = %c\n",  data.c);

    printf("\n");
    return 0;
}