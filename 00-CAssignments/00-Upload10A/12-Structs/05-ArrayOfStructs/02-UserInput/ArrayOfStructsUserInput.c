#include <stdio.h>

#define NAME_LENGTH   100
#define NUM_EMPLOYEES 3

struct Employee
{
    char  name[NAME_LENGTH];
    int   age;
    char  sex;
    float salary;
    char  maritalStatus;
};

typedef struct Employee Employee;

int main(void)
{
    // functions
    void MyGetString(char str[], int size);
    // variables
    Employee employees[NUM_EMPLOYEES];
    int i;

    // code
    printf("\n\n");
    for(i = 0; i < NUM_EMPLOYEES; ++i)
    {
        printf("\nData entry for emp %d\n", i + 1);
        printf("\nName: ");
        MyGetString(employees[i].name, NAME_LENGTH);
        printf("Age: ");
        scanf("%d", &employees[i].age);
        printf("Sex (M/F): ");
        employees[i].sex = getch();
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
        printf("Married (Y/N): ");
        employees[i].maritalStatus = getch();
    }

    printf("\n\n");
    printf("You entered \n");
    for(i = 0; i < NUM_EMPLOYEES; ++i)
    {
        printf("***** Employee %d *****\n", i + 1);
        printf("Name    : %s\n", employees[i].name);
        printf("Age     : %d\n", employees[i].age);
        printf("Sex     : %c\n", employees[i].sex);
        printf("Salary  : %f\n", employees[i].salary);
        printf("Married : %c\n", employees[i].maritalStatus);
    }

    printf("\n");
    return 0;
}

void MyGetString(char str[], int size)
{
    int i = 0;
    char ch = '\0';

    // code
    do
    {
        ch = getch();
        str[i] = ch;
        printf("%c", str[i]);
        ++i;
    } while((ch != '\r') && (i < size));

    if(i == size)
    {
        str[i - 1] = '\0';
    }
    else
    {
        str[i] = '\0';
    }
}
