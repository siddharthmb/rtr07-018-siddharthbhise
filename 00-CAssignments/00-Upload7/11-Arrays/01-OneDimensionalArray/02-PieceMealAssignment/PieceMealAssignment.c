#include <stdio.h>

int main(void)
{
    // variables
    int iArrayOne[5];
    int iArrayTwo[5];

    // code
    iArrayOne[0] = 5;
    iArrayOne[1] = 10;
    iArrayOne[2] = 15;
    iArrayOne[3] = 20;
    iArrayOne[4] = 25;

    printf("\n\n");
    printf("Piecemeal assignment (hardcoded) of iArrayOne[]\n");
    printf("--------- ---------- ----------- -- -----------\n");
    printf("iArrayOne[0] Element 1 = %d\n", iArrayOne[0]);
    printf("iArrayOne[1] Element 2 = %d\n", iArrayOne[1]);
    printf("iArrayOne[2] Element 3 = %d\n", iArrayOne[2]);
    printf("iArrayOne[3] Element 4 = %d\n", iArrayOne[4]);
    printf("iArrayOne[4] Element 5 = %d\n", iArrayOne[5]);

    printf("\n\n");

    printf("Enter the first element for iArrayTwo[]: ");
    scanf("%d", &iArrayTwo[0]);
    printf("Enter the second element for iArrayTwo[]: ");
    scanf("%d", &iArrayTwo[1]);
    printf("Enter the third element for iArrayTwo[]: ");
    scanf("%d", &iArrayTwo[2]);
    printf("Enter the fourth element for iArrayTwo[]: ");
    scanf("%d", &iArrayTwo[3]);
    printf("Enter the fifth element for iArrayTwo[]: ");
    scanf("%d", &iArrayTwo[4]);

    printf("Piecemeal assignment (hardcoded) of iArrayTwo[]\n");
    printf("--------- ---------- ----------- -- -----------\n");
    printf("iArrayTwo[0] Element 1 = %d\n", iArrayTwo[0]);
    printf("iArrayTwo[1] Element 2 = %d\n", iArrayTwo[1]);
    printf("iArrayTwo[2] Element 3 = %d\n", iArrayTwo[2]);
    printf("iArrayTwo[3] Element 4 = %d\n", iArrayTwo[3]);
    printf("iArrayTwo[4] Element 5 = %d\n", iArrayTwo[4]);

    return 0;
}