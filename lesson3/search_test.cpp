#include <gtest/gtest.h>
#include "search.hpp"
#include <iterator>
#include <vector>
#include <algorithm>

//-----------copy--------------
TEST(copy_test, test_1) {
    ASSERT_EQ(4, get_copy_time(5, 1, 2));
} 

TEST(copy_test, test_2) {
    ASSERT_EQ(0, get_copy_time(50, 0, 1));
} 

TEST(copy_test, test_3) {
    ASSERT_EQ(0, get_copy_time(50, 1, 0));
} 

TEST(copy_test, test_4) {
    ASSERT_EQ(5, get_copy_time(5, 1, 10));
} 

TEST(copy_test, test_5) {
    ASSERT_EQ(5, get_copy_time(5, 10, 1));
} 

TEST(copy_test, test_6) {
    ASSERT_EQ(46, get_copy_time(50, 10, 1));
}

TEST(copy_test, test_7) {
    ASSERT_EQ(96, get_copy_time(32, 7, 5));
}

TEST(copy_test, test_8) {
    ASSERT_EQ(30, get_copy_time(10, 5, 5));
}
//<-- copy end


//---------is subsequence---------
TEST(subsequence_test, test_1) {
    ASSERT_EQ(true, is_subsequence("uio", "quefio"));
} 

TEST(subsequence_test, test_2) {
    ASSERT_EQ(true, is_subsequence("emg", "emilgalimov"));
} 

TEST(subsequence_test, test_3) {
    ASSERT_EQ(false, is_subsequence("qwerty", "ewq"));
} 

TEST(subsequence_test, test_4) {
    ASSERT_EQ(false, is_subsequence("", "asdfg"));
} 

TEST(subsequence_test, test_5) {
    ASSERT_EQ(false, is_subsequence("sanvalsi", ""));
}

TEST(subsequence_test, test_6) {
    ASSERT_EQ(false, is_subsequence("aaaa", "aaa"));
}

TEST(subsequence_test, test_7) {
    ASSERT_EQ(true, is_subsequence("aaa", "aaaa"));
}

TEST(subsequence_test, test_8) {
    ASSERT_EQ(true, is_subsequence("pt", "miptdrec"));
}
//<-- is subsequence end

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}