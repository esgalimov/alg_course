#include "arrays.hpp"

void reverse_vector(std::vector<int>& vec) {
    if (vec.empty()) return;

    reverse_part(vec.begin(), --vec.end());
}


template <typename Iter>
void reverse_part(Iter head, Iter tail) {
    while (head < tail) {
        int tmp = *head;
        *head = *tail;
        *tail = tmp;

        head++; tail--;
    }
}

void cycle_shift_vector(std::vector<int>& vec, int k) {
    if (vec.empty()) return;
    int sz = vec.size();
    k = k % sz;

    reverse_part(vec.begin(), --vec.end());
    reverse_part(vec.begin(), vec.begin() + k - 1);
    reverse_part(vec.begin() + k, --vec.end());
}
