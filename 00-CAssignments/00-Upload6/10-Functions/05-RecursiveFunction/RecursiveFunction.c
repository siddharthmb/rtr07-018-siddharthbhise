#include <stdio.h>

int main(void)
{
    // functions
    void recursive(unsigned int);

    // variables
    unsigned int num;

    // code
    printf("\n\n");
    printf("Enter any number: ");
    scanf("%u", &num);

    recursive(num);

    printf("\n");
    return 0;
}

void recursive(unsigned int n)
{
    if(n <= 0)
    {
        printf("recursive(): %u\n", n);
        return;
    }

    printf("recursive(): %u\n", n);
    recursive(n - 1);
}
