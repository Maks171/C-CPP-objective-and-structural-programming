#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int a=6;

    switch(a) {
        case 1:
            printf("pon\n");
            break;
        case 2:
            printf("wt\n");
            break;
        case 3:
            printf("sr\n");
            break;
        case 4:
            printf("czw\n");
            break;
        case 5:
            printf("pt\n");
            break;
        case 6:
            printf("sob\n");
            break;
        case 7:
            printf("nd\n");
            break;
        default:
            printf("Podano niewlasciwa liczbe\n");
            break;
    }
    return EXIT_SUCCESS;
}
