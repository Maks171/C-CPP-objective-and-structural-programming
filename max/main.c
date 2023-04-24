#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    if (a>b) {
        return a;
    }
    else {
        return b;
    }
}

int main(void) {
    int x=22;
    int y=19;
    printf("Wieksza liczba to %d", max(x, y));

    return EXIT_SUCCESS;
}
