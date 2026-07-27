#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // functions
    void MyAlloc(int **ptr, unsigned int numElements);

    // variables
    int *pArray = NULL;
    unsigned int num_elements = 10;
    int i;

    // code
    printf("\n\n");
    MyAlloc(&pArray, num_elements);
    for(i = 0; i < num_elements; ++i)
    {
        *(pArray + i) = i * 10;
        printf("*(pArray + %d) = %d\n \t (pArray + %d) = %p\n", i, *(pArray + i), i, (pArray + i));
    }

    printf("\n\n");
    printf("Cleanup...\n");
    free(pArray);
    pArray = NULL;
    printf("Memory allocated to pArray has been freed...\n");

    printf("\n");
    return 0;
}

void MyAlloc(int **p, unsigned int numElements)
{
    // code
    *p = (int *)malloc(numElements * sizeof(int));
    if(*p == NULL)
    {
        printf("Failed to allocate memory for %zu bytes\n", sizeof(int) * numElements);
        exit(1);
    }
}
