#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int tab[10];

    for (int i=0; i<10; i++) {
        tab[i]=rand()%100;
        printf("%d ", tab[i]);
    }

    return EXIT_SUCCESS;
}