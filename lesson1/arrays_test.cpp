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
// <-- cycle shift shift end


//--------------------merge sorted vectors into new vector----------------
TEST(merge_sorted_vectors_new_vec_simple_test, test_1) {
    std::vector<int> vec1    = {1, 2, 3};
    std::vector<int> vec2    = {1, 2, 3};
    std::vector<int> new_vec = {1, 1, 2, 2, 3, 3};

    ASSERT_EQ(merge_sorted_vectors_into_new(vec1, vec2), new_vec);
}

TEST(merge_sorted_vectors_new_vec_simple_test, test_2) {
    std::vector<int> vec1    = {1, 4, 5, 7};
    std::vector<int> vec2    = {1, 2, 3, 6, 8};
    std::vector<int> new_vec = {1, 1, 2, 3, 4, 5, 6, 7, 8};

    ASSERT_EQ(merge_sorted_vectors_into_new(vec1, vec2), new_vec);
}

TEST(merge_sorted_vectors_new_vec_simple_test, test_3) {
    std::vector<int> vec1    = {-3, 2, 6, 13, 19};
    std::vector<int> vec2    = {-10, -4, -1, 0, 7, 8, 9, 18};
    std::vector<int> new_vec = {-10, -4, -3, -1, 0, 2, 6, 7, 8, 9, 13, 18, 19};

    ASSERT_EQ(merge_sorted_vectors_into_new(vec1, vec2), new_vec);
}

TEST(merge_sorted_vectors_new_empty_test, test_1) {
    std::vector<int> vec1 = {1, 4, 5, 7};
    std::vector<int> vec2;
    std::vector<int> new_vec = {1, 4, 5, 7};

    ASSERT_EQ(merge_sorted_vectors_into_new(vec1, vec2), new_vec);
}

TEST(merge_sorted_vectors_new_empty_test, test_2) {
    std::vector<int> vec1;
    std::vector<int> vec2    = {1, 4, 5, 7};
    std::vector<int> new_vec = {1, 4, 5, 7};

    ASSERT_EQ(merge_sorted_vectors_into_new(vec1, vec2), new_vec);
}

TEST(merge_sorted_vectors_new_empty_test, test_3) {
    std::vector<int> vec1;
    std::vector<int> vec2;
    std::vector<int> new_vec;

    ASSERT_EQ(merge_sorted_vectors_into_new(vec1, vec2), new_vec);
}
// <-- merge sorted vectors into new vector end


//--------------------merge sorted vectors into vec1----------------
TEST(merge_sorted_vectors_vec1_simple_test, test_1) {
    std::vector<int> vec1    = {1, 2, 3};
    std::vector<int> vec2    = {1, 2, 3};
    std::vector<int> new_vec = {1, 1, 2, 2, 3, 3};

    merge_sorted_vectors(vec1, vec2);

    ASSERT_EQ(vec1, new_vec);
}

TEST(merge_sorted_vectors_vec1_simple_test, test_2) {
    std::vector<int> vec1    = {1, 4, 5, 7};
    std::vector<int> vec2    = {1, 2, 3, 6, 8};
    std::vector<int> new_vec = {1, 1, 2, 3, 4, 5, 6, 7, 8};

    merge_sorted_vectors(vec1, vec2);

    ASSERT_EQ(vec1, new_vec);
}

TEST(merge_sorted_vectors_vec1_simple_test, test_3) {
    std::vector<int> vec1    = {-3, 2, 6, 13, 19};
    std::vector<int> vec2    = {-10, -4, -1, 0, 7, 8, 9, 18};
    std::vector<int> new_vec = {-10, -4, -3, -1, 0, 2, 6, 7, 8, 9, 13, 18, 19};

    merge_sorted_vectors(vec1, vec2);

    ASSERT_EQ(vec1, new_vec);
}

TEST(merge_sorted_vectors_vec1_empty_test, test_1) {
    std::vector<int> vec1 = {1, 4, 5, 7};
    std::vector<int> vec2;
    std::vector<int> new_vec = {1, 4, 5, 7};

    merge_sorted_vectors(vec1, vec2);

    ASSERT_EQ(vec1, new_vec);
}

TEST(merge_sorted_vectors_vec1_empty_test, test_2) {
    std::vector<int> vec1;
    std::vector<int> vec2    = {1, 4, 5, 7};
    std::vector<int> new_vec = {1, 4, 5, 7};

    merge_sorted_vectors(vec1, vec2);

    ASSERT_EQ(vec1, new_vec);
}

TEST(merge_sorted_vectors_vec1_empty_test, test_3) {
    std::vector<int> vec1;
    std::vector<int> vec2;
    std::vector<int> new_vec;

    merge_sorted_vectors(vec1, vec2);

    ASSERT_EQ(vec1, new_vec);
}
// <-- merge sorted vectors into vec1 end


//-------------even first----------------------
TEST(even_first_simple_test, test_1) {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    std::vector<int> ans = {2, 4, 6};

    even_first(vec);

    for (int i = 0; i < 3; i++) ASSERT_EQ(vec[i], ans[i]);
}

TEST(even_first_simple_test, test_2) {
    std::vector<int> vec = {7, 3, 2, 4, 1, 11, 8, 9};
    std::vector<int> ans = {2, 4, 8};

    even_first(vec);

    for (int i = 0; i < 3; i++) ASSERT_EQ(vec[i], ans[i]);
}

TEST(even_first_simple_test, test_3) {
    std::vector<int> vec = {7, 3, 1, 11, 9};
    std::vector<int> ans = {7, 3, 1, 11, 9};

    even_first(vec);

    ASSERT_EQ(vec, ans);
}

TEST(even_first_empty_test, test_1) {
    std::vector<int> vec;
    std::vector<int> ans;

    even_first(vec);

    ASSERT_EQ(vec, ans);
}
// <-- even first end


//-------------zero to end----------------------
TEST(zeros_to_simple_test, test_1) {
    std::vector<int> vec = {0, 0, 1, 0, 3, 12};

    zeros_to_end(vec);

    for (auto it = --vec.end(), itend = it - 3; it != itend; it--)
        ASSERT_EQ(0, *it);
}

TEST(zeros_to_simple_test, test_2) {
    std::vector<int> vec = {0, 33, 57, 88, 60, 0, 0, 80, 99};

    zeros_to_end(vec);

    for (auto it = --vec.end(), itend = it - 3; it != itend; it--)
        ASSERT_EQ(0, *it);
}

TEST(zeros_to_simple_test, test_3) {
    std::vector<int> vec = {0, 0, 0, 18, 16, 0, 0, 77, 99};

    zeros_to_end(vec);

    for (auto it = --vec.end(), itend = it - 5; it != itend; it--)
        ASSERT_EQ(0, *it);
}

TEST(zeros_to_empty_test, test_1) {
    std::vector<int> vec;
    std::vector<int> ans;

    zeros_to_end(vec);

    ASSERT_EQ(vec, ans);
}
// <-- zero to end end


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
