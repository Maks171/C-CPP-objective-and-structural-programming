#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double x=5;
    if(x>=2 && x<7 && x!=5) {
        printf("Nierownosci spelnione");
    }
    else {
        printf("Nierownosci niespelnione");
    }
    return EXIT_SUCCESS;
}
