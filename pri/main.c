#include <stdio.h>
#include <stdlib.h>

int prime(int n, int i) {
    if (i==n) {
        return 1;
    }
    if (n%i==0) {
        return 0;
    }
    return prime(n, i+1);
}

int fun(int n) {
    if(n==0 || n==1) {
        return 0;
    }
    else {
        return prime(n, 2);
    }
}

int main(void) {
    int n=13;
    printf("Czy %d jest liczba pierwsza? - %d\n", n, fun(n));

    return EXIT_SUCCESS;
}