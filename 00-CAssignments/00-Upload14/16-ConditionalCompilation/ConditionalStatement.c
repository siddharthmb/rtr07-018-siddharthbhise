#include <stdio.h>

#define MYPI 1

#ifdef MYPI
#if MYPI <= 0
    #undef  MYPI
    #define MYPI 3.14f
#elif MYPI == 1
    #undef  MYPI
    #define MYPI 3.1415679
#else
    #define MYPI 3.15f
#endif
#endif


#ifndef MYPI
    #define MYPI 0.0f
#endif

int main(void)
{
    // code
    printf("Value of PI is %.7f\n", MYPI);

    printf("\n");
    return 0;
}