#include <stdio.h>
#include <stdlib.h>

int suma(int n) {
    if(n==0) {
        return 0;
    }
    else {
        return (n%10 + suma(n/10));
    }
}

int main(void) {
    int n = 9645;

    printf("Suma cyfr liczby %d wynosi %d\n", n, suma(n));

    return EXIT_SUCCESS;
}
