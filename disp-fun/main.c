#include <stdio.h>
#include <stdlib.h>

int fun(int x, int y) {
    for(int i=1; i<=x; i++) {
        for(int j=1; j<=y; j++) {
            printf("$");
        }
        printf("\n");
    }
}
int main(void) {
    fun(3,6);
    return EXIT_SUCCESS;
}
