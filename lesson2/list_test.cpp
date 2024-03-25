#include <gtest/gtest.h>
#include "list.hpp"
#include <iterator>
#include <vector>
#include <algorithm>


//-------------------has cycle---------------------
TEST(cycle_simple_test, test_1) {
    my_list<int> lst;
    for (int i = 1; i < 7; i++) lst.push_front(i);

    ASSERT_EQ(false, lst.has_cycle());

    my_list<int>::iterator it = lst.begin();
    std::advance(it, 5);
    it.set_next(lst.begin());

    ASSERT_EQ(true, lst.has_cycle());
}

TEST(cycle_simple_test, test_2) {
    my_list<int> lst;
    for (int i = 1; i < 10; i++) lst.push_front(i);

    ASSERT_EQ(false, lst.has_cycle());

    my_list<int>::iterator it1 = lst.begin();
    my_list<int>::iterator it2 = lst.begin();
    std::advance(it1, 5);
    std::advance(it2, 8);
    it2.set_next(it1);

    ASSERT_EQ(true, lst.has_cycle());
}

TEST(cycle_simple_test, test_3) {
    my_list<int> lst;
    lst.push_front(1);

    ASSERT_EQ(false, lst.has_cycle());

    lst.begin().set_next(lst.begin());

    ASSERT_EQ(true, lst.has_cycle());
}

TEST(cycle_empty_test, test_1) {
    my_list<int> lst;
    
    ASSERT_EQ(false, lst.has_cycle());
}
//<--- has cycle end


//-------------reverse--------------
TEST(reverse_simple_test, test_1) {
    my_list<int> lst;
    for (int i = 1; i < 5; i++) lst.push_front(i);

    lst.reverse();

    my_list<int>::iterator it = lst.begin();

    for (int i = 1; i < 5; ++i) ASSERT_EQ(i, *it++);

    ASSERT_EQ(lst.end(), it);

    lst.reverse();
    it = lst.begin();
    for (int i = 4; i >= 1; --i) ASSERT_EQ(i, *it++);

    ASSERT_EQ(lst.end(), it);
}

TEST(reverse_simple_test, test_2) {
    my_list<int> lst;
    for (int i = 1; i < 20; i++) lst.push_front(i);

    lst.reverse();

    my_list<int>::iterator it = lst.begin();

    for (int i = 1; i < 20; ++i) ASSERT_EQ(i, *it++);

    ASSERT_EQ(lst.end(), it);

    lst.reverse();
    it = lst.begin();
    for (int i = 19; i >= 1; --i) ASSERT_EQ(i, *it++);

    ASSERT_EQ(lst.end(), it);
}

TEST(reverse_simple_test, test_3) {
    my_list<int> lst;
    lst.push_front(1);

    lst.reverse();
    ASSERT_EQ(1, *lst.begin());

    lst.reverse();
    ASSERT_EQ(1, *lst.begin());
}

TEST(reverse_empty_test, test_1) {
    my_list<int> lst;
    
    lst.reverse();
    ASSERT_EQ(true, lst.empty());
}
//<----------reverse end-------------


//-----------get middle node-----------
TEST(middle_simple_test, test_1) {
    my_list<int> lst;
    for (int i = 1; i < 6; i++) lst.push_front(i);

    ASSERT_EQ(3, *lst.get_middle_node());
}

TEST(middle_simple_test, test_2) {
    my_list<int> lst;
    for (int i = 1; i < 7; i++) lst.push_front(i);

    ASSERT_EQ(3, *lst.get_middle_node());
}

TEST(middle_simple_test, test_3) {
    my_list<int> lst;
    lst.push_front(10);

    ASSERT_EQ(10, *lst.get_middle_node());
}

TEST(middle_empty_test, test_1) {
    my_list<int> lst;

    ASSERT_EQ(lst.begin(), lst.get_middle_node());
}
//<--- get middle node end 

//----------erase------------
TEST(erase_simple_test, test_1) {
    my_list<int> lst;

    for (int i = 1; i < 7; i++) lst.push_front(i);

    lst.erase(6);

    my_list<int>::iterator it = lst.begin();

    for (int i = 5; i >= 1; --i) ASSERT_EQ(i, *it++);
}

TEST(erase_simple_test, test_2) {
    my_list<int> lst;

    for (int i = 1; i < 7; i++) lst.push_front(i);

    lst.erase(1);

    my_list<int>::iterator it = lst.begin();

    for (int i = 6; i > 1; --i) ASSERT_EQ(i, *it++);
}

TEST(erase_simple_test, test_3) {
    my_list<int> lst;

    for (int i = 1; i < 7; i++) lst.push_front(i);

    lst.erase(3);
    lst.erase(8);

    my_list<int>::iterator it = lst.begin();

    ASSERT_EQ(6, *it++);
    ASSERT_EQ(5, *it++);
    ASSERT_EQ(4, *it++);
    ASSERT_EQ(2, *it++);
    ASSERT_EQ(1, *it++);
}

TEST(erase_simple_test, test_4) {
    my_list<int> lst;
    lst.push_front(10);
    lst.erase(10);
    ASSERT_EQ(true, lst.empty());
}

TEST(erase_empty_test, test_5) {
    my_list<int> lst;
    lst.erase(10);
    ASSERT_EQ(true, lst.empty());
}
//<---- erase end 


//--------merge sorted lists----------
TEST(merge_simple_test, test_1) {
    std::vector vec1{8, 6, 3};
    std::vector vec2{11, 9, 7, 4};
    std::vector  ans{3, 4, 6, 7, 8, 9, 11};

    my_list<int> lst1;
    my_list<int> lst2;

    for (auto&& i : vec1) lst1.push_front(i); 
    for (auto&& i : vec2) lst2.push_front(i); 

    lst1.merge_sorted_lists(lst2);

    my_list<int>::iterator it = lst1.begin();

    while (it != lst1.end()) std::cout << *it++ << std::endl;

    it = lst1.begin(); 

    for (auto&& i : ans) ASSERT_EQ(i, *it++);
}

//<---- merge sorted lists end ------

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
