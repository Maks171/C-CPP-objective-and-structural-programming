#include <stdlib.h>
#include <stdio.h>

int silnia(int n) {
    int wynik=1;

    for (int i=1; i<=n; i++) {
        wynik=wynik*i;
    }
    return wynik;
}

int main(void) {
    int n=7;
    printf("%d! = %d", n, silnia(n));

    return EXIT_SUCCESS;
}