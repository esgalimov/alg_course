#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <list>

int get_copy_time(int doc_cnt, int time_x, int time_y) {
    if (time_x <= 0 || time_y <= 0 || doc_cnt <= 0) return 0;

    int left   = 0, 
        right  = (doc_cnt - 1) * std::max(time_x, time_y),
        middle = 0;
    
    while (left + 1 < right) {
        middle = (left + right) / 2;

        if ((middle / time_x + middle / time_y) < doc_cnt - 1)
              left = middle;
        else right = middle;
    }

    return right + std::min(time_x, time_y);
}

bool is_subsequence(std::string first, std::string second) {
    if (first.empty() || second.empty()) return false;

    std::queue<char> que;

    for (auto&& ch : first) que.push(ch);
    
    for (auto&& ch : second)
        if (que.front() == ch) que.pop();
    
    
    return que.empty();
}

int find_int_sqrt(int num) {
    if (num <= 0) return 0;

    int left = 0, right = num, middle = 0;

    while (left <= right) {
        middle = (left + right) / 2;

        if      (middle * middle > num) right = middle - 1;
        else if (middle * middle < num) left  = middle + 1;
        else                            return middle;
    }
    return right;
}

bool is_palindrome(std::string str) {
    if (str.empty()) return true;

    std::stack<char> stk;

    for (auto&& ch : str) stk.push(ch);

    for (auto&& ch : str) {
        if (stk.top() != ch) return false;
        
        stk.pop();
    }
    return true;
}

bool is_palindrome_iter(std::string str) {
    if (str.empty()) return true;

    auto head =   str.begin();
    auto tail = --str.end();

    while (head < tail) {
        if (*head != *tail) return false;

        ++head;
        --tail;
    }
    return true;
}

bool is_subsequence_iter(std::string first, std::string second) {
    if (first.empty() || second.empty()) return false;

    auto head1 = first.begin(), head2 = second.begin(),
         tail1 = first.end(), tail2 = second.end();

    while (head2 != tail2 && head1 != tail1) {
        if (*head2 == *head1) ++head1;

        ++head2;
    }
    return head1 == tail1;
}

std::string remove_duplicates(std::string str) {
    if (str.size() <= 1) return str;

    std::list<char> ch_list{str.begin(), str.end()};
    
    auto slow = ch_list.begin(), fast = ++ch_list.begin(), tail = ch_list.end();

    while (fast != tail) {
        //std::cout << *slow << *fast << std::endl;
        if (*slow == *fast) {
            auto saved_slow = std::prev(slow), 
                 saved_fast = std::next(fast);
            
            //while (saved_fast != tail && *saved_fast == *fast) ++saved_fast;

            ch_list.erase(slow, std::next(fast));

            slow = saved_slow;
            fast = saved_fast;
        }
        else {
            ++slow;
            ++fast;
        }
    }
    //for (auto&& ch : ch_list) std::cout << ch;
    //std::cout << std::endl;
    return std::string{ch_list.begin(), ch_list.end()};
}