#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int v1;
    double x;
    int v2;

    long adr1 =&v1;
    long adr2 =&v2;
    long kom = adr1-adr2;

    printf("Roznica komorek = %16ld\n", kom);
    printf("&v1         = %16ld\n", adr1);
    printf("&v2         = %16ld\n", adr2);


    return EXIT_SUCCESS;
}