#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double tab[5] = {11, 22, 53, 1, 0};
    int max=tab[0];

    for (int i=0; i<5; i++) {
        if (tab[i]>max) {
            max=tab[i];
        }
    }
    printf("Max= %d\n", max);

    return EXIT_SUCCESS;
}