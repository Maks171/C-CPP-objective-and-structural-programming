#include "shapes.hpp"

#include <numeric>

double calculate_total_area(const std::vector<Shape*>& shapes) {
    return std::accumulate(std::begin(shapes), std::end(shapes), 0.0,
                           [](double acc, const auto& shape_ptr) {
                               return acc + shape_ptr->area();
                           }); 
}
