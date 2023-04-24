#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int tab[] = {1, 2, 3, 4, 5, 6, 7};
    const int elem=sizeof(tab)/sizeof(int);
    for (int i=0; i<elem / 2; i++) {
        int ind_kon=(elem-1)-i;
        int x=tab[ind_kon];
        tab[ind_kon]=tab[i];
        tab[i]=x;
    }
    for (int i=0; i<elem; i++) {
        printf("%d ", tab[i]);
    }
    return EXIT_SUCCESS;
}