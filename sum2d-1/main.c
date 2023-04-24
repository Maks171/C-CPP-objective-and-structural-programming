#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int tab[2][3];
    int suma = 0;
    for (int i=0; i<2; i++) {
        for (int j=0; j<3; j++) {
            tab[i][j] = i+2*j;
        }
    }
    for (int i=0; i<2; i=i+2) {
        for (int j=0; j<3; j++) {
            suma=suma+tab[i][j];
        }
    }
    printf("Suma = %d\n", suma);

    return EXIT_SUCCESS;
}