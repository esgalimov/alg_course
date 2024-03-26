#include <iostream>
#include <stack>
#include <queue>
#include <string>

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