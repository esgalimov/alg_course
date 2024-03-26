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


//-------------find int sqrt--------------
TEST(sqrt_test, test_1) {
    ASSERT_EQ(4, find_int_sqrt(16));
}

TEST(sqrt_test, test_2) {
    ASSERT_EQ(0, find_int_sqrt(0));
}

TEST(sqrt_test, test_3) {
    ASSERT_EQ(0, find_int_sqrt(-23));
}

TEST(sqrt_test, test_4) {
    ASSERT_EQ(4, find_int_sqrt(17));
    ASSERT_EQ(4, find_int_sqrt(22));
    ASSERT_EQ(4, find_int_sqrt(24));
    ASSERT_EQ(5, find_int_sqrt(25));
}

TEST(sqrt_test, test_5) {
    ASSERT_EQ(16, find_int_sqrt(256));
}

TEST(sqrt_test, test_6) {
    ASSERT_EQ(22, find_int_sqrt(484));
}

TEST(sqrt_test, test_7) {
    ASSERT_EQ(27, find_int_sqrt(729));
}
//<--find int sqrt end


//-----------is_palindrome----------
TEST(palindrome_test, test_1) {
    ASSERT_EQ(true, is_palindrome("abba"));
}

TEST(palindrome_test, test_2) {
    ASSERT_EQ(false, is_palindrome("emil"));
}

TEST(palindrome_test, test_3) {
    ASSERT_EQ(true, is_palindrome("a"));
}

TEST(palindrome_test, test_4) {
    ASSERT_EQ(true, is_palindrome(""));
}

TEST(palindrome_test, test_5) {
    ASSERT_EQ(true, is_palindrome("qwertytrewq"));
}

TEST(palindrome_test, test_6) {
    ASSERT_EQ(false, is_palindrome("qwertyrewq"));
}
//<--is_palindrome end


//-----------is_palindrome_iter----------
TEST(palindrome_iter_test, test_1) {
    ASSERT_EQ(true, is_palindrome_iter("abba"));
}

TEST(palindrome_iter_test, test_2) {
    ASSERT_EQ(false, is_palindrome_iter("emil"));
}

TEST(palindrome_iter_test, test_3) {
    ASSERT_EQ(true, is_palindrome_iter("a"));
}

TEST(palindrome_iter_test, test_4) {
    ASSERT_EQ(true, is_palindrome_iter(""));
}

TEST(palindrome_iter_test, test_5) {
    ASSERT_EQ(true, is_palindrome_iter("qwertytrewq"));
}

TEST(palindrome_iter_test, test_6) {
    ASSERT_EQ(false, is_palindrome_iter("qwertyrewq"));
}
//<--is_palindrome_iter end


//-------------is_subsequence_iter-------------
TEST(subsequence_iter_test, test_1) {
    ASSERT_EQ(true, is_subsequence_iter("uio", "quefio"));
} 

TEST(subsequence_iter_test, test_2) {
    ASSERT_EQ(true, is_subsequence_iter("emg", "emilgalimov"));
} 

TEST(subsequence_iter_test, test_3) {
    ASSERT_EQ(false, is_subsequence_iter("qwerty", "ewq"));
} 

TEST(subsequence_iter_test, test_4) {
    ASSERT_EQ(false, is_subsequence_iter("", "asdfg"));
} 

TEST(subsequence_iter_test, test_5) {
    ASSERT_EQ(false, is_subsequence_iter("sanvalsi", ""));
}

TEST(subsequence_iter_test, test_6) {
    ASSERT_EQ(false, is_subsequence_iter("aaaa", "aaa"));
}

TEST(subsequence_iter_test, test_7) {
    ASSERT_EQ(true, is_subsequence_iter("aaa", "aaaa"));
}

TEST(subsequence_iter_test, test_8) {
    ASSERT_EQ(true, is_subsequence_iter("pt", "miptdrec"));
}
//<-- is_subsequence_iter end


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}