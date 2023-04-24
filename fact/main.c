#include <stdlib.h>
#include <stdio.h>

int silnia(int n){
    if(n==0) {
        return 1;
    }
    else if(n>1) {
        return (n*silnia(n-1));
        }
    }
int main(void) {
    int n;
    scanf( "%d", &n);
    printf("%d\n", silnia(n));

    return EXIT_SUCCESS;
}