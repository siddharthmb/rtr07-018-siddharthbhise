#include <stdio.h>

#define NAME_LENGTH     100
#define MARITAL_STATUS  10

struct Employee
{
    char    name[NAME_LENGTH];
    int     age;
    float   salary;
    char    sex;
    char    marital_status[MARITAL_STATUS];
};

typedef struct Employee Employee;

int main(void)
{
    // variables
    Employee employees[3];
    int i;

    // code
    printf("\n\n");
    strcpy(employees[0].name, "Sourabh");
    employees[0].age = 34;
    employees[0].sex = 'M';
    employees[0].salary = 200000.0f;
    strcpy(employees[0].marital_status, "Married");

    strcpy(employees[1].name, "Chinmay");
    employees[1].age = 35;
    employees[1].sex = 'M';
    employees[1].salary = 300000.0f;
    strcpy(employees[1].marital_status, "Single");

    strcpy(employees[2].name, "Sonali");
    employees[2].age = 33;
    employees[2].sex = 'F';
    employees[2].salary = 1300000.0f;
    strcpy(employees[2].marital_status, "Married");

    for(i = 0; i < 3; ++i)
    {
        printf("***** Employee %d *****\n", i + 1);
        printf("\tName          : %s\n", employees[i].name);
        printf("\tAge           : %d\n", employees[i].age);
        printf("\tSex           : %s\n", (employees[i].sex == 'M') ? "Male" : "Female");
        printf("\tSalary        : %.2f\n", employees[i].salary);
        printf("\tMarital status: %s\n\n", employees[i].marital_status);
    }

    printf("\n");
    return 0;
}