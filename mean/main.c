#include <stdio.h>
#include <stdlib.h>

double srednia(double a, double b, double c) {
    double sr = (a+b+c)/3;
    return sr;
}
int main(void) {
    double x1=4.0;
    double x2=6.0;
    double x3=12.0;
    printf("Srednia liczb %0.2f, %0.2f i %0.2f to %.2f", x1, x2, x3, srednia(x1, x2, x3));
    return EXIT_SUCCESS;
}
