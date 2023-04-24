#include <stdio.h>
#include <stdlib.h>

double fun(double x) {
    double dzialanie=(x*x*x+3*x)/(x*x+6);
    return dzialanie;
}
int main(void) {
    double a=5;
    printf("Wynik to %0.4f", fun(a));
    return EXIT_SUCCESS;
}
