#include <iostream>
#include "list.hpp"

int main() {
    my_list<int> lst;
    lst.push_front(1);
    lst.push_front(2);
    lst.push_front(3);
    lst.push_front(4);
    lst.push_front(5);


    my_list<int>::iterator start = lst.begin();
    for (; start != lst.end(); start++) {
        std::cout << *start << std::endl;
    }
    return 0;
}
