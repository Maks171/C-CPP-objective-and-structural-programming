#include <stdlib.h>
#include <stdio.h>

int main(void) {
    const int n = 23;

    for (int wiersz=1; wiersz<= n; wiersz++) {
        for (int kolumna=1; kolumna<= n; kolumna++) {
            if (wiersz==1 || wiersz==n || kolumna==1 || kolumna==n || wiersz==kolumna) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}