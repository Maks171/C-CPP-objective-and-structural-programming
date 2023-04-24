#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double tab[4] = {1.7, 2.0, 3, 8.3};
    double suma=0;

    for (int i=0; i<4; i++) {
        suma=suma+tab[i];
    }

    printf("Suma= %f\n", suma);

    return EXIT_SUCCESS;
}
