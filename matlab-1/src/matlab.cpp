#include "matlab.hpp"
#include <cstdlib>
#include <iostream>

int* add_vectors(int* v1, int* v2, std::size_t n) {
    int* v_sum = (int*) std::malloc(n * sizeof(int));
    if (v_sum == (int*) NULL) {
        return (int*) NULL;
    }

    for (std::size_t i = 0; i < n; i++) {
        v_sum[i] = v1[i] + v2[i];
    }

    return v_sum;
}

void print_vector(int* v, std::size_t n) {
    for (std::size_t i = 0; i < n; i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}
