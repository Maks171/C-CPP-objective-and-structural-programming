#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double a=2;
    double b=-4;
    double c=2;
    double delta;
    delta=b*b-4*a*c;
    printf("Delta=%.2f\n", delta);
    if(delta>0) {
        printf("Dwa pierwiastki");
    }
    else if(delta=0) {
        printf("Jeden pierwiastek");
    }
    else {
        printf("Brak pierwiastkow");
    }
    return EXIT_SUCCESS;
}
