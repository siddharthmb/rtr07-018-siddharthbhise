#include <stdio.h>

int main(void)
{
    // variables
    int iArray[] = {12, 24, 36, 48, 60, 72, 84, 96, 108, 120};
    float fArray[] = {9.8f, 54.0f, 765.7f, 6.5f};
    double dArray[] = {1.222, 2.333, 3.444};
    char cArray[] = {'A', 'S', 'T', 'R', 'O', 'M', 'E', 'D', 'I', 'C', 'O', 'M', 'P'};

    // code
    printf("\n\n");
    printf("Integer array elements and their addresses are as follows: \n");
    printf("iArray[0] = %d \t &iArray[0] = %p\n", *(iArray + 0), (iArray + 0));
    printf("iArray[1] = %d \t &iArray[1] = %p\n", *(iArray + 1), (iArray + 1));
    printf("iArray[2] = %d \t &iArray[2] = %p\n", *(iArray + 2), (iArray + 2));
    printf("iArray[3] = %d \t &iArray[3] = %p\n", *(iArray + 3), (iArray + 3));
    printf("iArray[4] = %d \t &iArray[4] = %p\n", *(iArray + 4), (iArray + 4));
    printf("iArray[5] = %d \t &iArray[5] = %p\n", *(iArray + 5), (iArray + 5));
    printf("iArray[6] = %d \t &iArray[6] = %p\n", *(iArray + 6), (iArray + 6));
    printf("iArray[7] = %d \t &iArray[7] = %p\n", *(iArray + 7), (iArray + 7));
    printf("iArray[8] = %d \t &iArray[8] = %p\n", *(iArray + 8), (iArray + 8));
    printf("iArray[9] = %d \t &iArray[9] = %p\n", *(iArray + 9), (iArray + 9));

    printf("\n\n");
    printf("Float array elements and their addresses are as follows:\n");
    printf("fArray[0] = %.2f \t &fArray[0] = %p\n", *(fArray + 0), (fArray + 0));
    printf("fArray[1] = %.2f \t &fArray[1] = %p\n", *(fArray + 0), (fArray + 0));
    printf("fArray[2] = %.2f \t &fArray[2] = %p\n", *(fArray + 0), (fArray + 0));
    printf("fArray[3] = %.2f \t &fArray[3] = %p\n", *(fArray + 0), (fArray + 0));

    printf("\n\n");
    printf("Double array elements and their addresses are as follows:\n");
    printf("dArray[0] = %lf \t &dArray[0] = %p\n", *(dArray + 0), (dArray + 0));
    printf("dArray[1] = %lf \t &dArray[1] = %p\n", *(dArray + 1), (dArray + 1));
    printf("dArray[2] = %lf \t &dArray[2] = %p\n", *(dArray + 2), (dArray + 2));

    printf("\n\n");
    printf("cArray[0]  = %c \t &cArray[0]  = %p\n", *(cArray + 0), (cArray + 0));
    printf("cArray[1]  = %c \t &cArray[1]  = %p\n", *(cArray + 1), (cArray + 1));
    printf("cArray[2]  = %c \t &cArray[2]  = %p\n", *(cArray + 2), (cArray + 2));
    printf("cArray[3]  = %c \t &cArray[3]  = %p\n", *(cArray + 3), (cArray + 3));
    printf("cArray[4]  = %c \t &cArray[4]  = %p\n", *(cArray + 4), (cArray + 4));
    printf("cArray[5]  = %c \t &cArray[5]  = %p\n", *(cArray + 5), (cArray + 5));
    printf("cArray[6]  = %c \t &cArray[6]  = %p\n", *(cArray + 6), (cArray + 6));
    printf("cArray[7]  = %c \t &cArray[7]  = %p\n", *(cArray + 7), (cArray + 7));
    printf("cArray[8]  = %c \t &cArray[8]  = %p\n", *(cArray + 8), (cArray + 8));
    printf("cArray[9]  = %c \t &cArray[9]  = %p\n", *(cArray + 9), (cArray + 9));
    printf("cArray[10] = %c \t &cArray[10] = %p\n", *(cArray + 10), (cArray + 10));
    printf("cArray[11] = %c \t &cArray[11] = %p\n", *(cArray + 11), (cArray + 11));
    printf("cArray[12] = %c \t &cArray[12] = %p\n", *(cArray + 12), (cArray + 12));

    printf("\n");
    return 0;
}