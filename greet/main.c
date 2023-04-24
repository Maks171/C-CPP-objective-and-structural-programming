#include <stdlib.h>
#include <stdio.h>

void powitaj(int n) {
    for (int i=1; i<=n; i++) {
        printf("Dzien dobry!\n");
    }
}

int main(void) {
    powitaj(6);

    return EXIT_SUCCESS;
}