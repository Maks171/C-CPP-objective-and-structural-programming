#include <stdlib.h>
#include <stdio.h>

int main(void) {
    const int dolary = 10;

    printf("%d$ = %.2f EUR\n", dolary, dolary*0.77);
    printf("%d$ = %.2f PLN\n", dolary, dolary*3.04);

    return EXIT_SUCCESS;
}