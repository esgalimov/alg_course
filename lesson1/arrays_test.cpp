#include <gtest/gtest.h>
#include <vector>
#include "arrays.hpp"

//----------------reverse array-----------------
TEST(reverse_simple_test, test_1) {
    std::vector<int>     vec = {1, 2, 3, 4, 5};
    std::vector<int> rev_vec = {5, 4, 3, 2, 1};
    reverse_vector(vec);

    ASSERT_EQ(vec, rev_vec);
}

TEST(reverse_simple_test, test_2) {
    std::vector<int>     vec = {1, 2, 3, 4, 5, 6};
    std::vector<int> rev_vec = {6, 5, 4, 3, 2, 1};
    reverse_vector(vec);

    ASSERT_EQ(vec, rev_vec);
}

TEST(reverse_one_elem_test, test_1) {
    std::vector<int>     vec = {1};
    std::vector<int> rev_vec = {1};
    reverse_vector(vec);

    ASSERT_EQ(vec, rev_vec);
}

TEST(reverse_two_elem_test, test_1) {
    std::vector<int>     vec = {1};
    std::vector<int> rev_vec = {1};
    reverse_vector(vec);

    ASSERT_EQ(vec, rev_vec);
}

TEST(reverse_empty_test, test_1) {
    std::vector<int> vec, rev_vec;
    reverse_vector(vec);

    ASSERT_EQ(vec, rev_vec);
}
// <-- reverse array end


//-------------cycle shift shift--------------
TEST(cycle_shift_simple_test, test_1) {
    std::vector<int>     vec = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> rev_vec = {5, 6, 7, 1, 2, 3, 4};

    cycle_shift_vector(vec, 3);

    ASSERT_EQ(vec, rev_vec);
}

TEST(cycle_shift_simple_test, test_2) {
    std::vector<int>     vec = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> rev_vec = {1, 2, 3, 4, 5, 6, 7};

    cycle_shift_vector(vec, 7);

    ASSERT_EQ(vec, rev_vec);
}

TEST(cycle_shift_simple_test, test_3) {
    std::vector<int>     vec = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> rev_vec = {1, 2, 3, 4, 5, 6, 7};

    cycle_shift_vector(vec, 0);

    ASSERT_EQ(vec, rev_vec);
}

TEST(cycle_shift_simple_test, test_4) {
    std::vector<int>     vec = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> rev_vec = {7, 1, 2, 3, 4, 5, 6};

    cycle_shift_vector(vec, 1);

    ASSERT_EQ(vec, rev_vec);
}

TEST(cycle_shift_big_k_test, test_1) {
    std::vector<int>     vec = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> rev_vec = {5, 6, 7, 1, 2, 3, 4};

    cycle_shift_vector(vec, 10);

    ASSERT_EQ(vec, rev_vec);
}

TEST(cycle_shift_one_elem_test, test_1) {
    std::vector<int>     vec = {1};
    std::vector<int> rev_vec = {1};

    cycle_shift_vector(vec, 0);
    cycle_shift_vector(vec, 1);
    cycle_shift_vector(vec, 10);
    cycle_shift_vector(vec, 20);

    ASSERT_EQ(vec, rev_vec);
}

TEST(cycle_shift_two_elem_test, test_1) {
    std::vector<int>     vec = {1, 2};
    std::vector<int> rev_vec = {2, 1};

    cycle_shift_vector(vec, 1);

    ASSERT_EQ(vec, rev_vec);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
