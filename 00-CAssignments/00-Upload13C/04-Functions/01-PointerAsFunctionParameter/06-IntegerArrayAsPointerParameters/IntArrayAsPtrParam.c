#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // functions
    void scaleArrayElements(int *arr, int totalElements, int scaleBy);

    // variables
    int *arr = NULL;
    int numElements;
    int i, scale;

    // code
    printf("\n\n");
    printf("Enter the number of elements in the array: ");
    scanf("%d", &numElements);

    arr = (int *)malloc(sizeof(int) * numElements);
    if(arr == NULL)
    {
        printf("Failed to allocated %zu bytes for int array\n", sizeof(int) * numElements);
        exit(1);
    }

    printf("Enter the elements... \n");
    for(i = 0; i < numElements; ++i)
    {
        printf("Element %d: \n", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\n\n");
    printf("Before scaling the elements in array\n\t[");
    for(i = 0; i < numElements; ++i)
    {
        printf(" %d", arr[i]);
    }
    printf(" ]\n");

    printf("Enter the number you want to scale(multiply) the elements with: ");
    scanf("%d", &scale);

    scaleArrayElements(arr, numElements, scale);

    printf("\n\n");
    printf("After scaling the elements in array\n\t[");
    for(i = 0; i < numElements; ++i)
    {
        printf(" %d", arr[i]);
    }
    printf(" ]\n");

    printf("\n\n");
    printf("Cleanup...\n");
    if(arr)
    {
        free(arr);
        arr = NULL;
        printf("Freed memory allocated for the array...\n");
    }

    printf("\n");
    return 0;
}

void scaleArrayElements(int *arr, int totalElements, int scale)
{
    // variables
    int i;

    // code
    for(i = 0; i < totalElements; ++i)
    {
        arr[i] = arr[i] * scale;
    }
}
