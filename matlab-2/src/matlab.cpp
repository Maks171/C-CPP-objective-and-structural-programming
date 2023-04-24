#include "matlab.hpp"
#include <cstdlib>
#include <iostream>
#include <cmath>

MatVect::MatVect(std::size_t n) {
    for (std::size_t i = 0; i < n; ++i) {
        v_.push_back(0);
    }
}

double MatVect::norm() {
    double sum_of_squares = 0.0;
    for (std::size_t i = 0; i < v_.size(); i++) {
        sum_of_squares += v_[i] * v_[i];
    }
    return sqrt(sum_of_squares);
}

MatVect add_vectors(MatVect v1, MatVect v2) {
    MatVect v_sum(v1.size());

    for (std::size_t i = 0; i < v1.size(); i++) {
        v_sum.set_elem(i, v1.get_elem(i) + v2.get_elem(i));
    }

    return v_sum;
}

void print_vector(MatVect v) {
    for (std::size_t i = 0; i < v.size(); i++) {
        std::cout << v.get_elem(i) << " ";
    }
    std::cout << std::endl;
}

