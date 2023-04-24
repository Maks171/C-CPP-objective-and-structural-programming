#define __USE_MINGW_ANSI_STDIO 1

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int fancy_range_sum1(int n) {
    int suma=0;
    for (int i = 1; i <= 8; i++) {
        if(i%n==0) {
            continue;
        }
        suma=suma+i;
    }
    return suma;
}

int fancy_range_sum2(int n, int stop) {
    int suma=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if (i==1 && j>=stop) {
                break;
            }
            suma=suma+i*j;
        }
    }
    return suma;
}

int fancy_range_sum3(int n, int stop) {
    int suma=0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i*j==stop) {
                goto koniec;
            }
            suma=suma+i*j;
        }
    }
    koniec:
    return suma;
}

int main(void) {
    // `counter` ma wartość logiczną PRAWDA także wówczas, gdy jest ujemny!
    for (int counter = 3, i = 1; counter; counter -= 2, ++i) {
        printf("i = %d, counter = %d\n", i, counter);
        if (i > 3) {
            break;
        }
    }

    assert(fancy_range_sum1(2) == 16);
    assert(fancy_range_sum1(3) == 27);

    // 1*1 + 2*1 + 2*2 + 2*3 + 3*1 + 3*2 + 3*3
    assert(fancy_range_sum2(3, 2) == 31);

    // 1*1 + 1*2 + 2*1 + 2*2 + 2*3 + 3*1 + 3*2 + 3*3
    assert(fancy_range_sum2(3, 3) == 33);

    // 1*1 + 1*2 + 1*3 + 2*1 + 2*2 (+ 2*3 - STOP)
    assert(fancy_range_sum3(3, 6) == 12);

    // 1*1 + 1*2 + 1*3 + 2*1 + 2*2 + 2*3 + 3*1 + 3*2 (+ 3*3 - STOP)
    assert(fancy_range_sum3(3, 9) == 27);

    return EXIT_SUCCESS;
}
