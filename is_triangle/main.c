#include <stdio.h>
#include <stdlib.h>

void is_triangle(int a, int b, int c) {
    if (a<b+c && b<a+c && c<a+b) {
        printf("Da sie zbudowac trojkat");
    }
    else {
        printf("Nie da sie zbudowac trojkata");
    }
}

int main(void) {
    is_triangle(3,4,10);
    return EXIT_SUCCESS;
}