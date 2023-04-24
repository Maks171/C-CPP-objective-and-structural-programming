#include <stdlib.h>
#include <stdio.h>

int main(void) {
    const int n=13;
    int i=0;
    for (i=2; (i<n) && (n%i!=0); i++)
        continue;

    if (i == n) {
        printf("Liczba jest pierwsza");
    }
    else {
        printf("Liczba nie jest pierwsza");
    }

    return EXIT_SUCCESS;
}