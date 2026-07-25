#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // variables
    int *pArray = NULL;
    int n, i;

    // code
    printf("\n\n");
    printf("Enter the number of elements for the array: ");
    scanf("%d", &n);

    if(n <= 0) 
    {
        printf("Enter 'n' greater than 0!");
        exit(1);
    }

    pArray = (int *)malloc(sizeof(int) * n);
    if(pArray == NULL)
    {
        printf("Memory allocation for %d bytes failed!!!\n", (int)(sizeof(int) * n));
        exit(1);
    }

    printf("Allocated memory for array successfully, now enter your %d elements\n", n);
    for(i = 0; i < n; ++i)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", (pArray + i));
    }

    printf("You Entered:\n");
    for(i = 0; i < n; ++i)
        printf("%d (@%p)\n", *(pArray + i), (pArray + i));

    printf("\n\n");
    
    printf("Freeing the array...\n");
    free(pArray);
    pArray = NULL;

    printf("\n");
    return 0;
}