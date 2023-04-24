#include <stdlib.h>
#include <stdio.h>
#define C11_TAG 201112L
#define C99_TAG 199901L

int get_dummy_cstd_identifier() {
#if defined(__STDC_VERSION__)
#if __STDC_VERSION__ >= C11_TAG
    return 2;
#elif __STDC_VERSION__ >= C99_TAG
    return 1;
        #else
        return -1;
#endif
#else
    return 0;
#endif
}

int main(void) {
    printf("Dummy C-version identifier: %d\n", get_dummy_cstd_identifier());

    return EXIT_SUCCESS;
}
