#include "gtest/gtest.h"

#include "shapes.hpp"

#include <vector>
#include <memory>
#include <algorithm>

TEST(SquareTest, area) {
    Square square(0.0, 0.0, 1.0);
    EXPECT_EQ(square.area(), 1.0);

    Shape& shape = square;
    EXPECT_EQ(shape.area(), 1.0);
}

TEST(CircleTest, area) {
    Circle circle(0.0, 0.0, 1.0);
    EXPECT_EQ(circle.area(), PI);

    Shape& shape = circle;
    EXPECT_EQ(shape.area(), PI);
}

TEST(ShapesAuxTest, totalAreaOfShapeCollection) {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(0.0, 0.0, 1.0));
    shapes.push_back(std::make_unique<Square>(0.0, 0.0, 1.0));

    std::vector<Shape*> shapes_rawptr;
    shapes_rawptr.reserve(shapes.size()); 
    std::transform(shapes.begin(), shapes.end(), std::back_inserter(shapes_rawptr),
                   [](const std::unique_ptr<Shape>& up) { return up.get(); });

    EXPECT_EQ(calculate_total_area(shapes_rawptr), 1.0 + PI);
}
