#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int is_square(int x) {
    double pierw=sqrt(x);
    if(x-pierw*pierw==0) {
        return 1;
    }
    else {
        return 0;
    }

}
int main(void) {
    int a=16;
    printf("Czy %d to kwadrat jakiejs liczby? - %d", a, is_square(a));

    return EXIT_SUCCESS;
}