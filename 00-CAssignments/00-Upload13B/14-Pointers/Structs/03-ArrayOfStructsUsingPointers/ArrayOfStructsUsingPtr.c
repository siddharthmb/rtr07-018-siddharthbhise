#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN       100
#define MARITAL_STATUS 10

typedef struct Employee
{
    char name[NAME_LEN];
    int age;
    char sex;
    float salary;
    char maritalStatus;
} Employee;

int main(void)
{
    // functions
    void my_gets(char[], int);

    // variables
    Employee *pEmpRecords = NULL;
    int totalEmployees, i;

    // code
    printf("\n\n");
    printf("Enter total number of employees: ");
    scanf("%d", &totalEmployees);

    pEmpRecords = (Employee *)malloc(totalEmployees * sizeof(Employee));
    if(pEmpRecords == NULL)
    {
        printf("Failed to allocate %zu bytes for employee records\n", sizeof(Employee) * totalEmployees);
        exit(1);
    }

    for(i = 0; i < totalEmployees; ++i)
    {
        printf("***** Employee record %d data entry \n", i + 1);
        printf("Name: ");
        my_gets(pEmpRecords[i].name, NAME_LEN);
        printf("Age : ");
        scanf("%d", &pEmpRecords[i].age);
        printf("Sex : ");
        pEmpRecords[i].sex = getch();
        printf("Salary : ");
        scanf("%f", &pEmpRecords[i].salary);
        printf("Married (Y/N) : ");
        pEmpRecords[i].maritalStatus = toupper(getch());
    }

    printf("\n\n");
    printf("Below are the employee records\n");
    for(i = 0; i < totalEmployees; ++i)
    {
        printf("Name: %s \t Age %d \t Sex: %c \t Salary: %.3f \t Married: %c\n",
            pEmpRecords[i].name,
            pEmpRecords[i].age,
            pEmpRecords[i].sex,
            pEmpRecords[i].salary,
            pEmpRecords[i].maritalStatus
        );
    }

    printf("\n\n");
    printf("Cleanup...");
    if(pEmpRecords)
    {
        free(pEmpRecords);
        pEmpRecords = NULL;
        printf("Freed memory allocated to pEmpRecords\n");
    }

    printf("\n");
    return 0;
}

void my_gets(char s[], int len)
{
    // code
    int i = 0;
    char c;
    while((c = getch()) != '\r')
    {
        s[i++] = c;
    }

    if(i == len) s[i - 1] = '\0';
    else s[i] = '\0';
}
