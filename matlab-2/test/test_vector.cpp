#include "gtest/gtest.h"
#include "matlab.hpp"

TEST(MatlabVectorTest, createWithSize) {
    MatVect v(2U);
    ASSERT_EQ(v.size(), 2U);
    EXPECT_EQ(v.get_elem(0), 0);
    EXPECT_EQ(v.get_elem(1), 0);
}

TEST(MatlabVectorTest, norm) {
    MatVect v(3U);
    v.set_elem(0, 3);
    v.set_elem(1, 4);

    EXPECT_EQ(v.norm(), 5);
}

TEST(MatlabVectorTest, add) {
    MatVect v1(2U);
    v1.set_elem(0, 1);
    v1.set_elem(1, 2);

    MatVect v2(2U);
    v2.set_elem(0, 4);
    v2.set_elem(1, 5);

    MatVect v_sum = add_vectors(v1, v2);

    ASSERT_EQ(v_sum.size(), 2U);
    EXPECT_EQ(v_sum.get_elem(0), 5);
    EXPECT_EQ(v_sum.get_elem(1), 7);
}

