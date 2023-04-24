#include <stdlib.h>
#include <stdio.h>

int main(void) {
    double S=12.0;
    double x=S;
    double x_pop;
    double dok = 10e-3;

    do {
        x_pop = x;
        x=0.5*(x_pop+S/x_pop);
    } while ((x-x_pop)<-dok || (x-x_pop)>dok);

    printf("Pierwiastek z %.2f to w przyblizeniu %.5f", S, x);

    return EXIT_SUCCESS;
}