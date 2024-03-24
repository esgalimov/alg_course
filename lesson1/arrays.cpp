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


std::vector<int> merge_sorted_vectors_into_new(std::vector<int>& vec1, std::vector<int>& vec2) {
    if (vec1.empty()) return vec2;
    if (vec2.empty()) return vec1;

    auto head1 = vec1.begin(), tail1 = vec1.end(),
         head2 = vec2.begin(), tail2 = vec2.end();

    std::vector<int> ret_vec;

    while (head1 != tail1 && head2 != tail2) {
        if (*head1 < *head2) ret_vec.push_back(*head1++);
        else                 ret_vec.push_back(*head2++);
    }

    while (head1 != tail1) ret_vec.push_back(*head1++);
    while (head2 != tail2) ret_vec.push_back(*head2++);

    return ret_vec;
}


void merge_sorted_vectors(std::vector<int>& vec1, std::vector<int>& vec2) {
    if (vec2.empty())                return;
    if (vec1.empty()) { vec1 = vec2; return; }

    int sz2 = vec2.size();

    vec1.resize(vec1.size() + vec2.size());

    auto head1        =   vec1.begin(),
         head2        =   vec2.begin(),
         tail1        = --vec1.end() - sz2,
         tail2        = --vec2.end(),
         tail_resized = --vec1.end();

    while (tail2 >= head2) {
        if (tail1 >= head1 && *tail1 > *tail2)
             *tail_resized = *tail1--;

        else *tail_resized = *tail2--;

        tail_resized--;
    }
}


void even_first(std::vector<int>& vec) {
    if (vec.empty()) return;

    auto even_finder = vec.begin(),
         even_puter  = vec.begin(),
         tail        = vec.end();

    while (even_finder != tail) {
        if (*even_finder % 2 == 0) {
            int tmp = *even_puter;
            *even_puter = *even_finder;
            *even_finder = tmp;

            even_puter++;
        }
        even_finder++;
    }
}

void zeros_to_end(std::vector<int>& vec) {
    if (vec.empty()) return;

    auto zero_finder = --vec.end(),
         zero_puter  = --vec.end(),
         head        =   vec.begin();

    while (zero_finder >= head) {
        if (*zero_finder == 0) {
            *zero_finder = *zero_puter;;
            *zero_puter = 0;

            zero_puter--;
        }
        zero_finder--;
    }
}
