#include <stdlib.h>
#include <stdio.h>

int main(void) {
    const int n=5;
    for (int wiersz=0; wiersz<n; wiersz++) {
        for (int kolumna=0; kolumna<n; kolumna++) {
            printf("%d", (wiersz+kolumna)%n+1);
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}