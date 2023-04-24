#include <stdlib.h>
#include <stdio.h>

void zamien(int* a, int* b)
{
    int temp;
    temp = *a;
    *a=*b;
    *b=temp;
}

int main(void) {
    int a = 4;
    int b = 5;
    int* pa = &a;
    int* pb = &b;
    zamien(pa,pb);

    if (a == 5 && b == 4) {
        printf("OK\n");
    } else {
        printf("Cos poszlo nie tak...\n");
    }

    return EXIT_SUCCESS;
}