#ifndef INCLUDE_MATLAB_HPP_
#define INCLUDE_MATLAB_HPP_
#include <cstddef>
#include <vector>

class MatVect {
public:
    MatVect(std::size_t n);

    int get_elem(std::size_t pos) { return v_[pos]; }
    void set_elem(std::size_t pos, int val) { v_[pos] = val; }

    std::size_t size() { return v_.size(); }

    double norm();

private:
    std::vector<int> v_;
};

MatVect add_vectors(MatVect v1, MatVect v2);

void print_vector(MatVect v);

#endif
