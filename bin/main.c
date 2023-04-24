#include <stdlib.h>
#include <stdio.h>

void bin(int n) {
    int r=n%2;
    if (n>=2) {
        bin(n/2);
    }
    printf("%d", r);
}

int main(void) {
    bin(9);
    return EXIT_SUCCESS;
}