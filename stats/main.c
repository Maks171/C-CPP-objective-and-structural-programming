#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double x=4.332;
    double y=7.81;
    double z=14.111;

    double suma=x+y+z;
    double srednia=suma/3;

    printf("Suma to: %lf\n", suma);
    printf("Srednia to: %lf\n", srednia);

    return EXIT_SUCCESS;
}