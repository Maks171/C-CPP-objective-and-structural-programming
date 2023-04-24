#include <stdlib.h>
#include <stdio.h>

int pierwiastki(int a, int b, int c) {
    int delta = b*b-4*a*c;
    if (delta>0) {
        return 2;
    }
    else if (delta==0) {
        return 1;
    }
    else {
        return 0;
    }
}

int main(void) {
    int a=2;
    int b=8;
    int c=2;
    printf("Liczba pierwiastkow: %d", pierwiastki(a, b, c));
    return EXIT_SUCCESS;
}