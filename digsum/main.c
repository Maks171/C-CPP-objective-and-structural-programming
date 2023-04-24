#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int cyfra=123;
    int nowa=cyfra;
    int suma=0;
    while(nowa>0) {
        suma=suma+nowa%10;
        nowa=nowa/10;
    }
    printf("Suma cyfr liczby %d to %d.\n", cyfra, suma);

    return EXIT_SUCCESS;
}